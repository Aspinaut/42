#include "../includes/minishell.h"

pid_t g_pid;

int	ret_err(int ret, char *msg)
{
	if (!msg)
		perror(PERR);
	else
		printf("%s\n", msg);
	return (ret);
}

void	ft_exit(t_shell *sh, t_parsing *ps, t_node *n, char *err)
{
	if (err)
		write(2, err, ft_strlen(err));
	final_free(sh, ps, n);
	exit(EXIT_FAILURE);
}

int not_emptycmd(char *cmd)
{
	int i;

	i = -1;
	if (cmd == NULL)
		return (1);
	while (cmd[++i])
	{
		if (!is_space(cmd[i]))
			return (1);
	}
	return (0);
}

// static void print_debug(t_parsing parstruct, t_node *nodes, t_shell shell)
// {
// 	(void)shell;
// 	/*		PRINT CMDS		*/

// 	int i = -1;
// 	while (++i < parstruct.pipe_nb + 1)
// 	{
// 		int j = -1;
// 		if (nodes[i].cmd)
// 			while (nodes[i].cmd[++j])
// 				printf("Node %d cmd % d : |%s|\n", i, j, nodes[i].cmd[j]);
// 	}

// 		/*		PRINT INFILES		*/

// 	i = -1;
// 	while (++i < parstruct.pipe_nb + 1)
// 	{
// 		printf("Node %d infile : |%s|\n", i, nodes[i].infiles);
// 	}

// 	// 	/*		PRINT OUTFILES		*/
	
// 	i = -1;
// 	while (++i < parstruct.pipe_nb + 1)
// 	{
// 		printf("Node %d outfile : |%s|\n", i, nodes[i].outfiles);
// 	}
// }

int main(int argc, char **argv, char **env)
{
	t_parsing	parstruct;
	t_node		*nodes;
	t_shell		shell;

	(void)argc;
	(void)argv;
	nodes = NULL;
	g_pid = 0;
	init_shell_struct(&shell, env); //faire un check sur le shell pendant l'init
	while (1)
	{
		// signal(SIGINT, handle_signal);
		// reinit struct pour le unset PATH
		parstruct.prompt = readline("minishell$ ");
		add_history(parstruct.prompt);
		if (not_emptycmd(parstruct.prompt))
		{
			nodes = parse(&parstruct, &shell);
			if (parstruct.stop_err)
			{
				final_free(NULL, &parstruct, nodes);
				continue ;
			}
			// print_debug(parstruct, nodes, shell);
			if (nodes)
			{
				exec(nodes, &shell);
				free_nodestruct(nodes);
			}
			free_parstruct(&parstruct);
		}
		else
		{
			parstruct.prompt = NULL;
			free(parstruct.prompt);
		}
	}
	free_shellstruct(&shell);
	
	return (0);
}

/* TESTS QUI LEAKS (sans exec)
	$< >

*/

/* A MODIFIER
	gestion des ">" dans le parsing (ne pas le considérer comme outfile dans ce cas)

*/
