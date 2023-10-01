/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_access.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:41:48 by isbarka           #+#    #+#             */
/*   Updated: 2023/02/12 15:41:50 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_file_access(char *str)
{
	int	check;

	check = access(str, R_OK);
	check_error(check, "access error");
}
