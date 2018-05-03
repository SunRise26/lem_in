/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:35:08 by vveselov          #+#    #+#             */
/*   Updated: 2018/04/26 22:16:00 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ans_wr(int i, char *s, char fl)
{
	char	*ant;

	ant = ft_itoa(i);
	if (fl)
		write(1, " ", 1);
	write(1, "L", 1);
	ft_putstr(ant);
	write(1, "-", 1);
	ft_putstr(s);
	free(ant);
}

void	all_in(int ants, char *end)
{
	int		ant;

	ant = 1;
	ans_wr(ant, end, 0);
	while (ant++ < ants)
		ans_wr(ant, end, 1);
	write(1, "\n", 1);
}

int		move_up(int dist, t_way *way, t_room *room, int j)
{
	int		i;

	i = 0;
	while (dist--)
		way = way->next;
	if (way->ant != 0)
	{
		i = 1;
		if (way->next == NULL)
			ans_wr(way->ant, get_type_room(2, room)->name, j);
		else
		{
			ans_wr(way->ant, way->next->name, j);
			way->next->ant = way->ant;
		}
		way->ant = 0;
	}
	return (i);
}

int		ways_up(t_ways *ways, t_room *room)
{
	int		dist;
	int		i;

	i = 0;
	while (ways)
	{
		dist = ways->dist;
		while (dist--)
			if (move_up(dist, ways->way, room, i))
				i = 1;
		ways = ways->next;
	}
	return (i);
}

void	lets_go(int ants, t_ways *ways, t_room *room, t_ways *begin)
{
	int		ant;
	int		sw;

	ant = 0;
	begin = ways;
	while (ant < ants)
	{
		sw = ways_up(begin, room);
		ways = begin;
		ways->way->ant = ++ant;
		ans_wr(ant, ways->way->name, sw);
		while (ways->next && ways->next->dist - begin->dist < ants - ant)
		{
			ways = ways->next;
			ways->way->ant = ++ant;
			ans_wr(ant, ways->way->name, 1);
		}
		write(1, "\n", 1);
	}
	while (ant)
	{
		ant = ways_up(begin, room);
		if (ant)
			write(1, "\n", 1);
	}
}
