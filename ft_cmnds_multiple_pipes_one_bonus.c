/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmnds_multiple_pipes_one_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:29:50 by isbarka           #+#    #+#             */
/*   Updated: 2023/02/12 18:06:37 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_first_cmnd_one_multiple(char **env, char **av)
{
	char	**paths;
	char	**temp;
	char	*valid_path;

	paths = errs(env);
	temp = ft_split_two(av[2], ' ');
	valid_path = ft_valid_path(paths, temp[0]);
	if (valid_path == NULL)
		check_error(-1, "command not found");
	execve(valid_path, temp, NULL);
	check_error(-1, "command error");
}

void	ft_first_cmnd_multiple(char **av, int *fd, char **env)
{
	int	a_file;
	int	check;
	int	test;

	a_file = open("/tmp/a", O_CREAT | O_RDWR | O_TRUNC, 0644);
	check_error(a_file, "open a fail");
	ft_check_file_access(av[1]);
	check = open(av[1], O_RDONLY);
	check_error(check, "error open av[1]");
	close(fd[0]);
	close(fd[1]);
	test = dup2(check, 0);
	check_error(test, "dup2 error");
	close(check);
	test = dup2(a_file, 1);
	check_error(test, "dup2 error");
	close(a_file);
	ft_first_cmnd_one_multiple(env, av);
}
