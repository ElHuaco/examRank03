/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_string_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:51:10 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/10/09 13:05:08 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

int			ft_strlen(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		;
	return (i);
}

int			ft_arrlen(char **arr)
{
	int		i;

	if (!arr)
		return (0);
	i = -1;
	while (arr[++i])
		;
	return (i);
}

char		*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*dup;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	dup[len] = '\0';
	i = -1;
	while (str[++i])
		dup[i] = str[i];
	return (dup);
}

char		*ft_strchr(char *str, char c)
{
	int		i;

	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (str + i);
	}
	return (NULL);
}

int			ft_strnchr(char *str, char c)
{
	int		i;
	int		count;

	if (!str)
		return (0);
	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}

char		**ft_split(char *str, char c)
{
	int		i;
	int		count;
	char	*pos;
	char	**table;

	count = ft_strnchr(str, c);
	table = malloc(sizeof(char *) * (count + 2));
	table[count + 1] = NULL;
	i = -1;
	while ((pos = ft_strchr(str, c)))
	{
		*pos = '\0';
		table[++i] = ft_strdup(str);
		str = pos + 1;
	}
	table[++i] = ft_strdup(str);
	return (table);
}

void		remove_empty_str_from_arr(char ***arr)
{
	int		i;
	int		size;
	int		count;
	char	**temp;

	size = ft_arrlen(*arr);
	count = 0;
	i = -1;
	while (*(*arr + ++i))
	{
		if (*(*(*arr + i)) == '\0')
			count++;
	}
	temp = malloc(sizeof(char *) * (size - count + 1));
	temp[size - count] = NULL;
	count = -1;
	i = -1;
	while (*(*arr + ++i))
	{
		if (*(*(*arr + i)) == '\0')
			continue;
		temp[++count] = ft_strdup(*(*arr + i));
	}
	free(*arr);
	*arr = temp;
}

unsigned int	ft_atoi(char *str)
{
	int				i;
	unsigned int	num;

	num = 0;
	i = -1;
	while (str[++i])
		num = num * 10 + (str[i] - '0');
	return (num);
}
