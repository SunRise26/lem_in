/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:49:22 by vveselov          #+#    #+#             */
/*   Updated: 2018/05/02 15:47:51 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_name_coords(char *s, t_room *room, int type)
{
	char	*name;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	j = i;
	if (i == 0 || s[i++] != ' ' || s[0] == 'L')
		return (-1);
	if ((room->coord[0] = ft_atoi_spec(&s[i], ' ')) == -1)
		return (-1);
	while (s[i] && s[i] != ' ')
		i++;
	if (!s[i++])
		return (-1);
	if ((room->coord[1] = ft_atoi_spec(&s[i], '\0')) == -1)
		return (-1);
	name = (char *)malloc(sizeof(char) * j + 1);
	i = -1;
	while (++i < j)
		name[i] = s[i];
	name[i] = '\0';
	room->name = name;
	return (type);
}

int		room_exist(t_room *room)
{
	t_room	*new;

	if (!room->next)
		return (0);
	new = room;
	while (new->next != NULL)
		new = new->next;
	while (room->next != NULL)
	{
		if (!ft_strcmp(room->name, new->name) || (room->coord[0] ==
			new->coord[0] && room->coord[1] == new->coord[1]))
			return (-2);
		room = room->next;
	}
	return (0);
}

int		room_st_fin(t_room *room, int sw)
{
	int		st;
	int		fin;

	st = 0;
	fin = 0;
	while (room)
	{
		if (room->type == 1)
			st++;
		else if (room->type == 2)
			fin++;
		room = room->next;
	}
	if (!sw && (st != 1 || fin != 1))
		return (-1);
	else if (sw == 1 && st != 0)
		return (-1);
	else if (sw == 2 && fin != 0)
		return (-1);
	return (1);
}

int		room_type(char **s, char **out, t_room *room, int *type)
{
	*type = 0;
	if (!ft_strcmp(*s, "##start"))
		*type = 1;
	else if (!ft_strcmp(*s, "##end"))
		*type = 2;
	if (*type != 0)
	{
		if (room_st_fin(room, *type) == -1)
			return (-2);
		free(*s);
		get_next_line(0, s);
		if (**s == 0)
			return (-1);
		*out = ft_concat(*out, *s);
	}
	while ((*s)[0] == '#' && ft_strcmp(*s, "##start") && ft_strcmp(*s, "##end"))
	{
		free(*s);
		get_next_line(0, s);
		if (**s == 0)
			return (-1);
		*out = ft_concat(*out, *s);
	}
	return (1);
}

int		rooms_check(char **s, t_room *room, char **out)
{
	int		type;
	t_room	*begin;
	int		sw;

	begin = room;
	if (room->name != NULL)
	{
		while (room->next != NULL)
			room = room->next;
		room->next = new_room();
		room = room->next;
	}
	if ((sw = room_type(s, out, begin, &type)) < 0)
		return (sw);
	if ((sw = get_name_coords(*s, room, type)) < 0)
		return (sw);
	room->type = type;
	return (room_exist(begin));
}
