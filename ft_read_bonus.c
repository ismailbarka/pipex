/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:31:37 by isbarka           #+#    #+#             */
/*   Updated: 2023/02/12 18:06:37 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_lim(char *str, char *lim)
{
	int	i;

	i = 0;
	while (str[i] && lim[i] && str[i] != '\n')
	{
		if (str[i] != lim[i])
			return (0);
		i++;
	}
	if ((str[i] != lim[i]) && (str[i] != '\n'))
		return (0);
	return (1);
}

void	ft_putstr(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_read_one(char *lim)
{
	char	*str;
	int		hd;

	hd = open("/tmp/temp_hd", O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (1)
	{
		write(2, "here_doc > ", 11);
		str = get_next_line(STDIN_FILENO);
		if (check_lim(str, lim) == 1)
			return (hd);
		ft_putstr(hd, str);
	}
	return (hd);
}
