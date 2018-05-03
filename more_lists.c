/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:11:25 by vveselov          #+#    #+#             */
/*   Updated: 2018/04/27 09:37:45 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way	*new_way(char *name)
{
	t_way	*way;

	way = (t_way *)malloc(sizeof(t_way));
	way->name = ft_strdup(name);
	way->ant = 0;
	way->next = NULL;
	return (way);
}

t_ways	*new_ways(void)
{
	t_ways	*ways;

	ways = (t_ways *)malloc(sizeof(t_ways));
	ways->way = NULL;
	ways->next = NULL;
	ways->dist = -1;
	return (ways);
}

t_ways	*next_ways(t_ways *ways)
{
	if (ways->way)
	{
		while (ways->next)
			ways = ways->next;
		ways->next = new_ways();
		ways = ways->next;
	}
	return (ways);
}

void	del_way(t_way *way)
{
	t_way	*cur;

	if (!way)
		return ;
	while (way)
	{
		cur = way;
		if (way->name)
			free(way->name);
		way = way->next;
		free(cur);
	}
}

void	del_ways(t_ways *ways)
{
	t_ways	*cur;

	if (!ways)
		return ;
	while (ways)
	{
		cur = ways;
		if (ways->way != NULL)
			del_way(ways->way);
		ways = ways->next;
		free(cur);
	}
}
