/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_creat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:39:12 by vveselov          #+#    #+#             */
/*   Updated: 2018/04/27 09:11:13 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		r_num(t_room *room, char *name)
{
	while (room)
	{
		if (!ft_strcmp(room->name, name))
		{
			if (room->type == 1 || room->type == -1)
				return (-1);
			else
				return (room->num);
		}
		room = room->next;
	}
	return (0);
}

void	fill_matrix(int **mx, t_room *room, t_link *link)
{
	int		x;
	int		y;

	while (link)
	{
		x = r_num(room, link->r1);
		y = r_num(room, link->r2);
		if (x == -1 || y == -1)
			;
		else
		{
			mx[x][y] = 1;
			mx[y][x] = 1;
		}
		link = link->next;
	}
}

int		room_num(t_room *room)
{
	int		i;

	i = 0;
	while (room)
	{
		room->num = i;
		i++;
		room = room->next;
	}
	return (i);
}

int		**matrix(int size)
{
	int		**mx;
	int		i;
	int		j;

	mx = (int **)malloc(sizeof(int *) * size);
	i = 0;
	while (i < size)
	{
		mx[i] = (int *)malloc(sizeof(int) * size);
		j = -1;
		while (++j < size)
			mx[i][j] = 0;
		i++;
	}
	return (mx);
}

void	del_matrix(int **mx, int size)
{
	int		i;

	i = 0;
	while (i < size)
		free(mx[i++]);
	free(mx);
}
