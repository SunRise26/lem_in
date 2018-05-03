/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:54:15 by vveselov          #+#    #+#             */
/*   Updated: 2018/04/26 18:36:39 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*get_type_room(int type, t_room *room)
{
	while (room)
	{
		if (room->type == type)
			return (room);
		room = room->next;
	}
	return (NULL);
}

t_room	*get_num_room(int num, t_room *room)
{
	while (room)
	{
		if (room->num == num)
			return (room);
		room = room->next;
	}
	return (NULL);
}

t_room	*get_name_room(char *name, t_room *room)
{
	while (room)
	{
		if (!ft_strcmp(room->name, name))
			return (room);
		room = room->next;
	}
	return (NULL);
}

t_room	*get_mx_room(int **mx, int size, int num, t_room *room)
{
	int		i;
	t_room	*r;

	i = 0;
	while (i < size)
	{
		if (mx[num][i] == 1 && (r = get_num_room(i, room))->visited == 0)
			return (r);
		i++;
	}
	return (NULL);
}
