/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:20:34 by isbarka           #+#    #+#             */
/*   Updated: 2023/02/12 20:08:55 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*new_s;
	int		i;

	i = 0;
	s_len = ft_strlen(s);
	new_s = malloc(s_len + 1);
	if (!new_s)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

static char	*ft_error(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*to_return;
	char	*temp;

	temp = (char *)s1;
	i = 0;
	if (!s1 || !s2)
		return (ft_error(s1, s2));
	to_return = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!to_return)
		return (0);
	while (*s1 != '\0')
	{
		to_return[i] = *s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		to_return[i] = *s2++;
		i++;
	}
	to_return[i] = '\0';
	free(temp);
	return (to_return);
}
