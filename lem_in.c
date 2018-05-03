/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:46:17 by vveselov          #+#    #+#             */
/*   Updated: 2018/04/27 10:23:08 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		fin_ch(t_room *room, t_link *link)
{
	int		i;

	i = 0;
	if (!room || !link->r1 || !link->r2)
		return (1);
	while (link)
	{
		if (!ft_strcmp(room->name, link->r1) ||
			!ft_strcmp(room->name, link->r2))
			i++;
		link = link->next;
	}
	if (i != 0)
		return (0);
	return (1);
}

void	free_all(t_room *room, t_link *link, t_ways *ways, char *out)
{
	del_room(room);
	del_link(link);
	del_ways(ways);
	if (out)
		free(out);
}

void	ants_out(t_room *room, t_ways *ways, int ants_n, char *out)
{
	ft_putendl(out);
	write(1, "\n", 1);
	if (ways->dist == 0)
		all_in(ants_n, get_type_room(2, room)->name);
	else
		lets_go(ants_n, ways, room, ways);
}

int		main(void)
{
	int		ants_n;
	t_room	*room;
	t_link	*link;
	t_ways	*ways;
	char	*out;

	out = NULL;
	ways = NULL;
	room = new_room();
	link = new_link();
	if (check_input(&ants_n, room, link, &out))
		ft_putendl("ERROR");
	else if (!(fin_ch(get_type_room(2, room), link)) &&
	(ways = bfs(room, link))->dist != -1)
		ants_out(room, ways, ants_n, out);
	else
		ft_putendl("ERROR");
	free_all(room, link, ways, out);
	return (0);
}
