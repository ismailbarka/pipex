/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:25:48 by isbarka           #+#    #+#             */
/*   Updated: 2023/02/12 20:11:31 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_valid_path(char **paths, char *str)
{
	int		i;
	char	*temp;

	i = 0;
	if (access(str, X_OK) == 0)
		return (str);
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], str);
		if (access(temp, X_OK) == 0)
			return (temp);
		free(temp);
		i++;
	}
	return (NULL);
}

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str)
	{
		write(2, &str[i], 1);
	}
}

void	check_error(int x, char *str)
{
	if (x < 0)
	{
		perror(str);
		exit(0);
	}
}
