/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmnds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:20:44 by isbarka           #+#    #+#             */
/*   Updated: 2023/02/12 18:21:27 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_first_cmnd_one(char **env, char **av)
{
	char	**paths;
	char	**temp;
	char	*valid_path;

	paths = errs(env);
	temp = ft_split_two(av[2], ' ');
	valid_path = ft_valid_path(paths, temp[0]);
	if (valid_path == NULL)
	{
		write(2, "command not found", 17);
		exit(1);
	}
	execve(valid_path, temp, NULL);
	exit(1);
}

void	ft_first_cmnd(char **av, int *fd, char **env)
{
	int	check;

	ft_check_file_access(av[1]);
	check = open(av[1], O_RDONLY);
	check_error(check, "open error");
	close(fd[0]);
	dup2(check, 0);
	close(check);
	dup2(fd[1], 1);
	close(fd[1]);
	ft_first_cmnd_one(env, av);
}

void	ft_last_cmnd_one(char **env, char **av)
{
	char	**paths;
	char	**temp;
	char	*valid_path;

	paths = errs(env);
	temp = ft_split_two(av[3], ' ');
	valid_path = ft_valid_path(paths, temp[0]);
	if (valid_path == NULL)
	{
		write(2, "command not found", 17);
		exit(-1);
	}
	execve(valid_path, temp, NULL);
	check_error(-1, "error command");
	exit(1);
}

void	ft_last_cmnd(char **av, int *fd, char **env)
{
	int	check;
	int	test;

	check = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	check_error(check, "open error");
	close(fd[1]);
	test = dup2(check, 1);
	check_error(test, "dup2 error");
	close(check);
	test = dup2(fd[0], 0);
	check_error(test, "dup2 error");
	ft_last_cmnd_one(env, av);
}
