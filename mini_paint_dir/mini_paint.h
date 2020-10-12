/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:56:46 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/10/12 15:57:23 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
# define MINI_PAINT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

# define EARG "Error: argument\n"
# define EFILE "Error: Operation file corrupted\n"

typedef struct	s_circle
{
	char		type;
	float		xc;
	float		yc;
	float		radius;
	char		fill;
}				t_circle;

int				ft_strlen(char *str);
int				error_exit(char *error_str);

#endif
