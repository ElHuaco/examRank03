/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:57:39 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/10/12 15:57:47 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

int		error_exit(char *error_str)
{
	write(1, error_str, ft_strlen(error_str));
	return (1);
}

int		ft_strlen(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		;
	return (i);
}
