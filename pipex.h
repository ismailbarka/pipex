/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:59:39 by isbarka           #+#    #+#             */
/*   Updated: 2023/02/12 17:51:24 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>

char	**ft_split(const char *s, char c);
char	**ft_split_two(const char *s, char c);
char	**errs(char **env);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_count_pipes(int ac);
void	check_error(int x, char *str);
void	ft_check_file_access(char *str);
void	ft_first_cmnd(char **av, int *fd, char **env);
void	ft_last_cmnd(char **av, int *fd, char **env);
char	*ft_valid_path(char **paths, char *str);
int		ft_check_here_doc(char *str);
void	ft_first_cmnd_multiple(char **av, int *fd, char **env);
void	ft_middle_cmnd_multiple_even(char **av, int *fd, char **env, int i);
void	ft_middle_cmnd_multiple_odd(char **av, int *fd, char **env, int i);
void	ft_last_cmnd_multiple(char **av, int *fd, char **env, int i);
void	ft_bzero(void *s, size_t n);
int		ft_read_one(char *lim);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
void	ft_first_cmnd_hd(char **av, char **env);
void	ft_last_cmnd_hd(char **av, char **env);
void	ft_putstr(int fd, char *str);
char	**str_count(char **str, const char *s, char c);
int		word_len(const char *s, char c);
void	ft_first_cmnd_one_multiple(char **env, char **av);
void	ft_first_cmnd_multiple(char **av, int *fd, char **env);
char	**ft_free_all(char **str);

#endif
