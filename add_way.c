/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_way.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 21:45:20 by vveselov          #+#    #+#             */
/*   Updated: 2018/04/26 21:50:02 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_new_way(int dist_num[2], t_room *room, t_link *link, t_ways *ways)
{
	t_way	*new;
	t_room	*tmp;
	t_way	*begin;
	int		id;

	ways = next_ways(ways);
	ways->dist = dist_num[0];
	tmp = get_num_room(dist_num[1], room);
	tmp->type = -1;
	new = new_way(tmp->name);
	begin = new;
	while (1)
	{
		id = tmp->num;
		st_next_cmp(dist_num, room, link, tmp);
		tmp = get_num_room(dist_num[1], room);
		if (tmp->type == 2 || tmp->type == 1)
			break ;
		tmp->type = -1;
		new->next = new_way(tmp->name);
		new = new->next;
	}
	ways->way = begin;
}

int		new_w(t_ways *ways, t_room *room, t_link *link)
{
	t_room	*st;
	t_link	*begin;
	int		dist_num[2];

	begin = link;
	dist_num[0] = -1;
	st = get_type_room(1, room);
	while (link)
	{
		st_cmp(dist_num, room, link, st);
		link = link->next;
	}
	if (dist_num[0] == -1)
		return (0);
	add_new_way(dist_num, room, begin, ways);
	return (1);
}
