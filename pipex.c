/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:18:49 by isbarka           #+#    #+#             */
/*   Updated: 2023/02/12 20:13:17 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int	id;
	int	fd[2];

	if (ac == 5)
	{
		id = pipe(fd);
		check_error(id, "piping error");
		id = fork();
		check_error(id, "fork error");
		if (id == 0)
			ft_first_cmnd(av, fd, env);
		id = fork();
		check_error(id, "fork error");
		if (id == 0)
			ft_last_cmnd(av, fd, env);
		wait(NULL);
	}
	else
		check_error(-1, "error arguments");
}
