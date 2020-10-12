/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 12:11:47 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/10/12 15:05:13 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

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

static int	belongs_to_rectangle(float x, float y, t_rectangle *rect)
{
	float		xbr;
	float		ybr;

	xbr = rect->xtl + rect->width;
	ybr = rect->ytl + rect->height;
	if ((x < rect->xtl) || (x > xbr) || (y < rect->ytl) || (y > ybr))
		return (0);
	else if (rect->type == 'R')
		return (1);
	else
	{
		if (((x - rect->xtl) < 1 + 0e6) || ((xbr - x) < 1 + 0e6)
			|| ((y - rect->ytl) < 1 + 0e6) || ((ybr - y) < 1 + 0e6))
			return (1);
		return (0);
	}
}

static int	output_update(char ***output, t_rectangle *rect)
{
	int		i;
	int		j;

	if (((rect->type != 'R') && (rect->type != 'r')) || (rect->width <= 0e6)
		|| (rect->height <= 0e6))
		return (1);
	i = -1;
	while (*(*output + ++i))
	{
		j = -1;
		while (*(*(*output + i) + ++j))
		{
			if ((belongs_to_rectangle((float)j, (float)i, rect)))
				*(*(*output + i) + j) = rect->fill;
		}
	}
	return (0);
}

static int	execute_operations(FILE *op_file)
{
	int				args_scanned;
	t_rectangle		rect;
	char			**output;

	if ((set_dim_and_bg(op_file, &output)))
		return (1);
	while ((args_scanned = fscanf(op_file, "%c %f %f %f %f %c\n",
		&rect.type, &rect.xtl, &rect.ytl, &rect.width, &rect.height,
		&rect.fill)) == 6)
	{
		if ((output_update(&output, &rect)))
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
