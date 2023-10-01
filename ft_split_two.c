/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:20:41 by isbarka           #+#    #+#             */
/*   Updated: 2023/02/12 17:09:45 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memcpy_two(void *dest, const void *src, size_t n)
{
	unsigned char	*my_dest;
	unsigned char	*my_src;
	size_t			i;

	if (n < 0)
		n = ft_strlen(src);
	my_dest = (unsigned char *)dest;
	my_src = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		my_dest[i] = my_src[i];
		i++;
	}
	return (dest);
}

static char	*ft_word_two(const char *s, char c)
{
	char	*str;
	int		len;

	len = word_len(s, c);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
	{
		free(str);
		return (0);
	}
	ft_memcpy_two(str, s, len);
	str[len] = '\0';
	return (str);
}

static char	**ft_free_all_two(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

char	**ft_split_two(const char *s, char c)
{
	char	**str;
	int		i;

	if (!s)
		return (0);
	str = NULL;
	str = str_count(str, s, c);
	if (!str)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			str[i] = ft_word_two(s, c);
			if (!str[i])
				return (ft_free_all_two(str));
			i++;
		}
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (str);
}
