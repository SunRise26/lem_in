/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:15:17 by vveselov          #+#    #+#             */
/*   Updated: 2018/05/02 15:51:26 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_putendl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	write(1, "\n", 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int		ft_atoi_spec(char *str, char stop)
{
	int	ret;
	int	min;

	ret = 0;
	min = 1;
	if (*str == '\0' || *str == stop)
		return (-1);
	if (*str == '-')
	{
		min = -1;
		str++;
	}
	while (*str && *str != stop)
	{
		if (*str >= '0' && *str <= '9')
			ret = ret * 10 + (*str - 48) * min;
		else
			return (-1);
		str++;
	}
	return (ret);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	new[i] = '\0';
	i = -1;
	while (s[++i])
		new[i] = s[i];
	return (new);
}

char	*ft_concat(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	if (!s1)
		return (ft_strdup(s2));
	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	new = (char *)malloc(sizeof(char) * (i + j + 2));
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	new[i++] = '\n';
	j = -1;
	while (s2[++j])
		new[i++] = s2[j];
	new[i] = '\0';
	free(s1);
	return (new);
}
