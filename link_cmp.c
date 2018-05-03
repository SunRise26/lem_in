/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 21:27:42 by vveselov          #+#    #+#             */
/*   Updated: 2018/04/26 21:35:33 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	st_cmp(int dist_num[2], t_room *room, t_link *link, t_room *st)
{
	t_room	*tmp;

	if (!ft_strcmp(st->name, link->r1) && (tmp = get_name_room(link->r2, room)))
	{
		if (tmp->dist != 0 && tmp->type != -1 &&
		(dist_num[0] == -1 || dist_num[0] > tmp->dist))
		{
			dist_num[0] = tmp->dist;
			dist_num[1] = tmp->num;
		}
	}
	else if (!ft_strcmp(st->name, link->r2) &&
	(tmp = get_name_room(link->r1, room)))
	{
		if (tmp->dist != 0 && tmp->type != -1 &&
		(dist_num[0] == -1 || dist_num[0] > tmp->dist))
		{
			dist_num[0] = tmp->dist;
			dist_num[1] = tmp->num;
		}
	}
}

void	st_next_cmp(int dist_num[2], t_room *room, t_link *link, t_room *st)
{
	t_room	*tmp;

	while (link)
	{
		if (!ft_strcmp(st->name, link->r1) &&
		(tmp = get_name_room(link->r2, room)) && tmp->type != -1 &&
		dist_num[0] - tmp->dist == 1)
		{
			dist_num[0] = tmp->dist;
			dist_num[1] = tmp->num;
			return ;
		}
		else if (!ft_strcmp(st->name, link->r2) &&
		(tmp = get_name_room(link->r1, room)) &&
		tmp->type != -1 && dist_num[0] - tmp->dist == 1)
		{
			dist_num[0] = tmp->dist;
			dist_num[1] = tmp->num;
			return ;
		}
		link = link->next;
	}
}

int		st_end(t_room *st, t_room *end, t_link *link, t_ways *ways)
{
	while (link)
	{
		if ((!ft_strcmp(st->name, link->r1) || !ft_strcmp(end->name, link->r1))
		&& (!ft_strcmp(st->name, link->r2) || !ft_strcmp(end->name, link->r2)))
		{
			ways->dist = 0;
			return (1);
		}
		link = link->next;
	}
	return (0);
}
