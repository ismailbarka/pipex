/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:43:00 by isbarka           #+#    #+#             */
/*   Updated: 2023/02/12 20:13:37 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_middle_cmnd_multiple_one_(char **av, int *fd, char **env, int i)
{
	if (i % 2 == 0)
		ft_middle_cmnd_multiple_even(av, fd, env, i);
	else
		ft_middle_cmnd_multiple_odd(av, fd, env, i);
}

void	multiple_pipes_one(char **av, int *fd, char **env, int ac)
{
	int	i;
	int	id;

	i = 0;
	while (i < ac - 5)
	{
		id = fork();
		check_error(id, "fork error");
		if (id == 0)
			ft_middle_cmnd_multiple_one_(av, fd, env, i);
		wait(0);
		i++;
	}
	id = fork();
	check_error(id, "error fork");
	if (id == 0)
		ft_last_cmnd_multiple(av, fd, env, i);
	wait(0);
	unlink("/tmp/a");
	unlink("/tmp/b");
}

void	multiple_pipes(int ac, char **av, char **env)
{
	int	fd[2];
	int	check;

	check = pipe(fd);
	check = fork();
	if (check == 0)
		ft_first_cmnd_multiple(av, fd, env);
	wait(0);
	multiple_pipes_one(av, fd, env, ac);
}

void	here_doc_pipe( char **av, char **env)
{
	int	id;

	id = fork();
	check_error(id, "fork error");
	if (id == 0)
		ft_first_cmnd_hd(av, env);
	wait(NULL);
	id = fork();
	if (id == 0)
		ft_last_cmnd_hd(av, env);
	wait(NULL);
	unlink("/tmp/temp_hd");
	unlink("/tmp/b_hd");
}

int	main(int ac, char **av, char **env)
{
	if (ft_check_here_doc(av[1]))
	{
		if (ac == 6)
			here_doc_pipe(av, env);
		else
			check_error(-1, "error arguments");
	}
	else
	{
		if (ac >= 5)
			multiple_pipes(ac, av, env);
		else
			check_error(-1, "error arguments");
	}
	return (0);
}
