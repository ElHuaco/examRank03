/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:01:13 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/10/12 15:01:15 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

# define EARG "Error: argument\n"
# define EFILE "Error: Operation file corrupted\n"

typedef struct	s_rectangle
{
	char		type;
	float		xtl;
	float		ytl;
	float		width;
	float		height;
	char		fill;
}				t_rectangle;

int				ft_strlen(char *str);
int				error_exit(char *error_str);

#endif
