const axios = require('axios')
const dotenv = require('dotenv').config()
const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
})

let teamProjects = [
  { 
    teamId: 0,
    comments: [
      "Super bien explique !",
      "Nice !",
    ], 
  },
]

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

async function getTeamsProjectUrls(token, projectId)
{
  // add function to run through total api response pages
  let teamsProjectRaw
  let teamsProjectUrls = []
  let teamsProjectEndpoint = `/v2/projects/${projectId}/projects_users`
  let options = {
    url: baseUrl + teamsProjectEndpoint,
    method: 'GET',
    data: { access_token: token, page: 1 },
  }
  try {
    teamsProjectRaw = await axios(options)
  } catch (e) {
    console.log(e)
  }
  teamsProjectRaw.data.map(teams => {
    teams.teams.map(team => {
      teamsProjectUrls.push(team.url)
    })
  })
  return teamsProjectUrls
}

async function mapComments(teamGroupsRaw, teamComments)
{
  await teamGroupsRaw.map(group => {
    group.scale_teams.map(eval => {
      console.log(eval)
      teamComments.push({
        id: eval.id,
        comment: eval.comment,
        feedback: eval.feedback,
      })
    })
  })
  return teamComments
}

async function getTeamComments(token, teamsProjectUrls)
{
  let teamGroupsRaw
  let teamComments = []
  teamsProjectUrls.map(teamProject => {  
    let options = {
      url: teamProject,
      method: 'GET',
      data: { access_token: token, page: 1 },
    }
    try {
      teamGroupsRaw = axios(options)
      .then(
        mapComments(teamGroupsRaw, teamComments)
      )
    } catch (e) {
      console.log(e)
    }
  })
  return teamComments
}

async function main()
{
  let token = await generateToken()
  let teamsProjectUrls = await getTeamsProjectUrls(token, 2)
  let teamComments = await getTeamComments(token, teamsProjectUrls)
}

main()