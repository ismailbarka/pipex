/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmnds_multiple_pipes_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:29:50 by isbarka           #+#    #+#             */
/*   Updated: 2023/02/12 18:06:37 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_middle_cmnd_multiple_one(char **env, char **av, int i)
{
	char	**paths;
	char	**temp;
	char	*valid_path;

	paths = errs(env);
	temp = ft_split_two(av[i + 3], ' ');
	valid_path = ft_valid_path(paths, temp[0]);
	if (valid_path == NULL)
		check_error(-1, "command not found");
	execve(valid_path, temp, NULL);
	check_error(-1, "command error");
}

void	ft_middle_cmnd_multiple_odd(char **av, int *fd, char **env, int i)
{
	int	b_file;
	int	test;
	int	a_file;

	b_file = open("/tmp/b", O_CREAT | O_RDONLY, 0644);
	check_error(b_file, "b_file open fail");
	a_file = open("/tmp/a", O_CREAT | O_RDWR | O_TRUNC, 0644);
	check_error(a_file, "a_file open fail");
	test = dup2(b_file, 0);
	check_error(test, "dup2 error");
	test = dup2(a_file, 1);
	check_error(test, "dup2 error");
	close(fd[0]);
	close(fd[1]);
	close(a_file);
	close(b_file);
	ft_middle_cmnd_multiple_one(env, av, i);
}

void	ft_middle_cmnd_multiple_even(char **av, int *fd, char **env, int i)
{
	int	a_file;
	int	b_file;
	int	test;

	a_file = open("/tmp/a", O_CREAT | O_RDONLY, 0644);
	check_error(a_file, "a_file open fail");
	b_file = open("/tmp/b", O_CREAT | O_RDWR | O_TRUNC, 0644);
	check_error(b_file, "b_file open fail");
	test = dup2(a_file, 0);
	check_error(test, "dup2 error");
	test = dup2(b_file, 1);
	check_error(test, "dup2 error");
	close(fd[0]);
	close(fd[1]);
	close(a_file);
	close(b_file);
	ft_middle_cmnd_multiple_one(env, av, i);
}

void	ft_last_cmnd_one_multiple(char **env, char **av, int i)
{
	char	**paths;
	char	**temp;
	char	*valid_path;

	paths = errs(env);
	temp = ft_split_two(av[i + 3], ' ');
	valid_path = ft_valid_path(paths, temp[0]);
	if (valid_path == NULL)
		check_error(-1, "command not found");
	execve(valid_path, temp, NULL);
	check_error(-1, "command error");
}

void	ft_last_cmnd_multiple(char **av, int *fd, char **env, int i)
{
	int	file;
	int	check;
	int	test;

	if (i % 2 == 1)
		file = open("/tmp/b", O_RDONLY);
	else
		file = open("/tmp/a", O_RDONLY);
	check = open(av[i + 4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	check_error(check, "open error");
	close(fd[1]);
	test = dup2(check, 1);
	check_error(test, "dup2 error");
	test = dup2(file, 0);
	check_error(test, "dup2 error");
	close(check);
	close(file);
	ft_last_cmnd_one_multiple(env, av, i);
}
