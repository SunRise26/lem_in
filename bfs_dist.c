/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:23:45 by vveselov          #+#    #+#             */
/*   Updated: 2018/04/27 09:14:06 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	level_up(int **q, int **q1, int size)
{
	free(*q);
	*q = *q1;
	*q1 = queue(size);
}

void	add_dist(int **mx, int size, int *q, t_room *room)
{
	t_room	*cur;
	t_room	*mx_ch;
	int		i;
	int		*q1;

	q1 = queue(size);
	cur = get_type_room(2, room);
	cur->visited = 1;
	queue_in(q, cur->num);
	i = 1;
	while (q[2] != 0)
	{
		cur = queue_out(q, room);
		while ((mx_ch = get_mx_room(mx, size, cur->num, room)) != NULL)
		{
			mx_ch->visited = 1;
			mx_ch->dist = i;
			queue_in(q1, mx_ch->num);
		}
		if (q[2] == 0 && ++i)
			level_up(&q, &q1, size);
	}
	free(q);
	free(q1);
}

void	mx_null(int **mx, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			mx[i][j] = 0;
	}
}

void	dist_null(t_room *room)
{
	while (room)
	{
		if (room->type != -1)
		{
			room->dist = 0;
			room->visited = 0;
		}
		room = room->next;
	}
}

t_ways	*bfs(t_room *room, t_link *link)
{
	t_ways	*ways;
	int		mx_size;
	int		**mx;
	int		*q;

	ways = new_ways();
	if (st_end(get_type_room(1, room), get_type_room(2, room), link, ways))
		return (ways);
	mx_size = room_num(room);
	mx = matrix(mx_size);
	while (1)
	{
		q = queue(mx_size);
		fill_matrix(mx, room, link);
		add_dist(mx, mx_size, q, room);
		if (new_w(ways, room, link) == 0)
			break ;
		mx_null(mx, mx_size);
		dist_null(room);
	}
	del_matrix(mx, mx_size);
	return (ways);
}
