/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:46:40 by vveselov          #+#    #+#             */
/*   Updated: 2018/04/26 18:36:52 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_room(t_room *room)
{
	t_room	*cur;

	while (room != NULL)
	{
		if (room->name != NULL)
			free(room->name);
		cur = room;
		room = room->next;
		free(cur);
	}
}

void	del_link(t_link *link)
{
	t_link	*cur;

	while (link != NULL)
	{
		if (link->r1 != NULL)
			free(link->r1);
		if (link->r2 != NULL)
			free(link->r2);
		cur = link;
		link = link->next;
		free(cur);
	}
}

t_room	*new_room(void)
{
	t_room	*room;

	room = (t_room *)malloc(sizeof(t_room));
	room->name = NULL;
	room->next = NULL;
	room->visited = 0;
	room->dist = 0;
	room->type = 0;
	return (room);
}

void	del_last_nameless_room(t_room *room)
{
	if (!room->next)
		return ;
	while (room->next->name)
		room = room->next;
	if (room->next)
	{
		free(room->next);
		room->next = NULL;
	}
}

t_link	*new_link(void)
{
	t_link	*link;

	link = (t_link *)malloc(sizeof(t_link));
	link->r1 = NULL;
	link->r2 = NULL;
	link->next = NULL;
	return (link);
}
