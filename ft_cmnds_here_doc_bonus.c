/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmnds_here_doc_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:29:34 by isbarka           #+#    #+#             */
/*   Updated: 2023/02/12 21:00:21 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_first_cmnd_one_hd(char **env, char **av)
{
	char	**paths;
	char	**temp;
	char	*valid_path;

	paths = errs(env);
	temp = ft_split_two(av[3], ' ');
	valid_path = ft_valid_path(paths, temp[0]);
	if (valid_path == NULL)
		check_error(-1, "command not found");
	execve(valid_path, temp, NULL);
	check_error(-1, "error command");
}

void	ft_first_cmnd_hd(char **av, char **env)
{
	int	hd;
	int	temp;
	int	test;

	ft_read_one(av[2]);
	hd = open("/tmp/temp_hd", O_RDWR | O_RDONLY);
	check_error(hd, "open error");
	test = dup2(hd, 0);
	check_error(test, "dup error");
	close(hd);
	temp = open("/tmp/b_hd", O_CREAT | O_RDWR | O_TRUNC, 0644);
	check_error(temp, "open error");
	test = dup2(temp, 1);
	check_error(test, "dup error");
	ft_first_cmnd_one_hd(env, av);
}

void	ft_last_cmnd_one_hd(char **env, char **av)
{
	char	**paths;
	char	**temp;
	char	*valid_path;

	paths = errs(env);
	temp = ft_split_two(av[4], ' ');
	valid_path = ft_valid_path(paths, temp[0]);
	if (valid_path == NULL)
		check_error(-1, "command not found");
	execve(valid_path, temp, NULL);
	check_error(-1, "error command");
}

void	ft_last_cmnd_hd(char **av, char **env)
{
	int	temp;
	int	check;
	int	test;

	temp = open("/tmp/b_hd", O_RDWR);
	check_error(temp, "open error");
	check = open(av[5], O_CREAT | O_RDWR | O_RDONLY, 0644);
	check_error(check, "open error");
	test = dup2(check, 1);
	check_error(test, "dup2 error");
	close(check);
	test = dup2(temp, 0);
	check_error(test, "dup2 error");
	close(temp);
	ft_last_cmnd_one_hd(env, av);
}
