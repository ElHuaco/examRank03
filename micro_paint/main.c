/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 12:11:47 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/10/09 13:18:01 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

static int	error_exit(char *error_str)
{
	write(1, error_str, ft_strlen(error_str));
	return (1);
}

static void	ft_addchar(char **str, char c)
{
	int		i;
	int		len;
	char	*temp;

	len = ft_strlen(*str);
	temp = malloc(sizeof(char) * (len + 2));
	temp[len + 1] = '\0';
	i = -1;
	while (*(*str + ++i))
		temp[i] = *(*str + i);
	temp[i] = c;
	free(*str);
	*str = temp;
}

static int	set_dimensions_and_bg(unsigned int *dim, char *str)
{
	char			*pos;
	char			*pos2;
	unsigned int	i;
	unsigned int	j;

	pos = ft_strchr(str, ' ');
	if (!(pos))
		return (1);
	*pos = '\0';
	*dim = ft_atoi(str);
	pos2 = ft_strchr(pos + 1, ' ');
	if (!(pos2))
		return (1);
	*pos2 = '\0';
	*(dim + 1) = ft_atoi(pos + 1);
	*(dim + 2) = ft_atoi(pos2 + 1) + 48;
	i = -1;
	while (++i < dim[1])
	{
		j = -1;
		while (++j < dim[0])
			write(1, dim + 2, 1);
		write(1, "\n", 1);
	}
	return (0);
}

static int	execute_orders(char **op)
{
	int				i;
	unsigned int	dim_and_bg[3];

	i = -1;
	while (op[++i])
	{
		if ((i == 0) && (set_dimensions_and_bg(dim_and_bg, op[i])))
			return (error_exit(EFILE));
	}
	return (0);
}

int			main(int argc, char **argv)
{
	FILE	*op_file;
	char	*text;
	char	*buff;
	char	**operations;

	if (argc != 2)
		return (error_exit(EARG));
	if (!(op_file = fopen(argv[1], "r")))
		return (error_exit(EFILE));
	text = calloc(1, sizeof(char));
	buff = calloc(1, sizeof(char));
	while ((fread(buff, sizeof(char), 1, op_file)))
		ft_addchar(&text, *buff);
	free(buff);
	operations = ft_split(text, '\n');
	free(text);
	remove_empty_str_from_arr(&operations);
	int i = -1; while (operations[++i])
		printf("line %d: %s\n", i, operations[i]);
	return (execute_orders(operations));
}



