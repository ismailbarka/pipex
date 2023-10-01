/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:41:50 by isbarka           #+#    #+#             */
/*   Updated: 2023/02/12 03:41:51 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*t;

	i = 0;
	t = (unsigned char *)s;
	while (i < n)
	{
		t[i] = 0;
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (((char *)s + i + 1));
		i++;
	}
	if (c == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
