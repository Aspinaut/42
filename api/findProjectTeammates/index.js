const axios = require('axios')
const dotenv = require('dotenv').config()
const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
})

const baseUrl = 'https://api.intra.42.fr'

async function generateToken()
{
  let token
  let tokenEndpoint = '/oauth/token'
  let credentials = {
    grant_type: 'client_credentials',
    client_id: process.env.client_id,
    client_secret: process.env.client_secret,
  }
  let options = {
    url: baseUrl + tokenEndpoint,
    method: 'POST',
    data: credentials,
  }
  try {
    token = await axios(options)
  } catch (e) {
    console.log(e)
  }
  return (token.data.access_token)
}

async function findProjectId(projectName, token)
{
  let projectsEndpoint = '/v2/projects'
  let totalPages = 42
  let projectId

  // trouver le nombre de pages totales !
  for (let page=1; page <= totalPages; page++)
  {
    try {
      let result = await axios({
        url: baseUrl + projectsEndpoint,
        method: 'GET',
        data: {
          access_token: token,
          page: page,
        },
      })
      console.log(result.headers.link[0])
      result.data.forEach((project) => {
        // !! utiliser des regex pour éviter les erreurs de frappe
        if (project.name.toLowerCase() === projectName.toLowerCase())
        {
          projectId = project.id
          return (projectId)
        }
      })
    } catch (e) {
      console.log(e)
    }
  }
  return (projectId)
}

async function findUsers(school, projectId, token)
{
  let projectsUsersEndpoint = `/v2/projects/${projectId}/projects_users`
  let totalPages = 368
  let users = []

  // trouver le nombre de pages totales !
  for (let page=1; page < totalPages; page++)
  {
    try {
      let result = await axios({
        url: baseUrl + projectsUsersEndpoint,
        method: 'GET',
        data: {
          access_token: token,
          page: page,
        },
      })
      result.data.forEach((project) => {
        if (project.teams[0].repo_url?.includes(school)
          && project.teams[0]["closed?"] === false)
        {
          console.log(project.user.login)
          users.push(project.user.login)
        }
      })
    } catch (e) {
      console.log(e)
    }
  }
  return (users)
}

async function main()
{
  let token = await generateToken()
  let projectId = await findProjectId("printf", token)
  // let users = await findUsers("s19.be", 2, token)

  // console.log(users)
  // readline.question('Enter your project name : \n', projectName => {
  //   let projectId = await findProjectId(projectName, token)
  //   if (!projectId)
  //     console.log('Your project hasn\'t been found, sorry...')
  //   else
  //     console.log(`Your project ID is ${projectId}!`)
  //   readline.close()
  // })
}

main()
