/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:47:35 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/10/09 13:05:59 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define EARG "Error: argument\n"
# define EFILE "Error: Operation file corrupted\n"

/*
** micro_string_utils.c
*/
int			ft_strlen(char *str);
int			ft_arrlen(char **arr);
char		*ft_strchr(char *str, char c);
int			ft_strnchr(char *str, char c);
char		*ft_strdup(char *str);
char		**ft_split(char *str, char c);
void		remove_empty_str_from_arr(char ***arrdir);
unsigned int	ft_atoi(char *str);
#endif

