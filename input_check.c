/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 21:12:50 by vveselov          #+#    #+#             */
/*   Updated: 2018/04/27 10:18:25 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ants_num(char *s, int *n)
{
	int		num;

	if ((num = ft_atoi_spec(s, '\0')) <= 0)
	{
		free(s);
		return (-1);
	}
	free(s);
	*n = num;
	return (1);
}

int		input_rooms(t_room *room, t_link *link, char *l, char **out)
{
	int		sw;

	if ((sw = rooms_check(&l, room, out)) < 0)
	{
		if (*l == 0 || sw == -2 || room_st_fin(room, 0) == -1)
		{
			free(l);
			return (-1);
		}
		del_last_nameless_room(room);
		if (links_check(l, link, room) == -1)
		{
			free(l);
			return (-1);
		}
		free(l);
		return (2);
	}
	free(l);
	return (1);
}

int		input_links(t_room *room, t_link *link, char *l)
{
	if (links_check(l, link, room) == -1)
	{
		free(l);
		return (0);
	}
	free(l);
	return (1);
}

int		check_input(int *ants_n, t_room *room, t_link *link, char **out)
{
	char	*l;
	int		fun;

	fun = 0;
	while (fun != -1 && get_next_line(0, &l))
	{
		if (*l)
			*out = ft_concat(*out, l);
		if (l[0] == '#' && ft_strcmp(l, "##start") && ft_strcmp(l, "##end"))
			free(l);
		else if (fun == 0)
			fun = ants_num(l, ants_n);
		else if (fun == 1)
		{
			fun = input_rooms(room, link, l, out);
		}
		else if (!input_links(room, link, l))
			return (0);
	}
	if (fun == -1)
		return (1);
	return (0);
}
