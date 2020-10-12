/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:57:55 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/10/12 16:19:10 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

static int	set_dim_and_bg(FILE *op_file, char ***output)
{
	int		width;
	int		height;
	char	bg;
	int		i;

	if ((fscanf(op_file, "%d %d %c\n", &width, &height, &bg) != 3))
		return (1);
	if ((width > 300) || (height > 300) || (width < 1) || (height < 1))
		return (1);
	*output = malloc(sizeof(char *) * (height + 1));
	*(*output + height) = NULL;
	i = -1;
	while (++i < height)
	{
		*(*output + i) = calloc(width + 1, sizeof(char));
		memset(*(*output + i), bg, width);
	}
	return (0);
}

static int	belongs_to_circle(float x, float y, t_circle *circle)
{
	float		distance;

	distance = sqrtf(powf(circle->xc - x, 2) + powf(circle->yc - y, 2));
	if ((distance - circle->radius) > 10e-6)
		return (0);
	else if (circle->type == 'C')
		return (1);
	else
	{
		if (((distance - circle->radius) < 1 + 10e-6)
			&& ((distance - circle->radius) > -1 - 10e-6))
			return (1);
		return (0);
	}
}

static int	output_update(char ***output, t_circle *circle)
{
	int		i;
	int		j;

	if (((circle->type != 'C') && (circle->type != 'c'))
		|| (circle->radius <= 0e6))
		return (1);
	i = -1;
	while (*(*output + ++i))
	{
		j = -1;
		while (*(*(*output + i) + ++j))
		{
			if ((belongs_to_circle((float)j, (float)i, circle)))
				*(*(*output + i) + j) = circle->fill;
		}
	}
	return (0);
}

static int	execute_operations(FILE *op_file)
{
	int				args_scanned;
	t_circle		circle;
	char			**output;

	if ((set_dim_and_bg(op_file, &output)))
		return (1);
	while ((args_scanned = fscanf(op_file, "%c %f %f %f %c\n",
		&circle.type, &circle.xc, &circle.yc, &circle.radius,
		&circle.fill)) == 5)
	{
		if ((output_update(&output, &circle)))
			return (1);
	}
	if (args_scanned == -1)
	{
		while (output[++args_scanned])
		{
			write(1, output[args_scanned], ft_strlen(output[args_scanned]));
			free(output[args_scanned]);
			write(1, "\n", 1);
		}
		free(output);
		return (0);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	FILE	*op_file;

	if (argc != 2)
		return (error_exit(EARG));
	if (!(op_file = fopen(argv[1], "r")))
		return (error_exit(EFILE));
	if (!(execute_operations(op_file)))
		return (0);
	return (error_exit(EFILE));
}
