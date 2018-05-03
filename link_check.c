/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:52:39 by vveselov          #+#    #+#             */
/*   Updated: 2018/04/26 18:36:49 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*curr_link(t_link *link)
{
	if (link->r1 != NULL)
	{
		while (link->next != NULL)
			link = link->next;
		link->next = new_link();
		link = link->next;
	}
	return (link);
}

char	*get_link_name(char *s, char sp, int *i)
{
	char	*name;
	int		j;

	*i = 0;
	if (!s[*i])
		return (NULL);
	while (s[*i] && s[*i] != sp)
		(*i)++;
	if (sp != '\0' && (!s[*i] || !s[*i + 1]))
		return (NULL);
	name = (char *)malloc(sizeof(char) * (*i) + 1);
	name[*i] = '\0';
	j = -1;
	while (++j < *i)
		name[j] = s[j];
	return (name);
}

int		link_exist(t_link *link, char *r1, char *r2)
{
	if (!ft_strcmp(r1, r2))
		return (1);
	if (!link->r1)
		return (0);
	while (link != NULL)
	{
		if (!ft_strcmp(link->r1, r1) && !ft_strcmp(link->r2, r2))
			return (1);
		else if (!ft_strcmp(link->r1, r2) && !ft_strcmp(link->r2, r1))
			return (1);
		link = link->next;
	}
	return (0);
}

int		wrong_lname(t_room *room, char *r1, char *r2)
{
	t_room	*st;
	int		l1;
	int		l2;

	st = room;
	l1 = 0;
	l2 = 0;
	while (room)
	{
		if (!ft_strcmp(room->name, r1))
			l1++;
		room = room->next;
	}
	while (st)
	{
		if (!ft_strcmp(st->name, r2))
			l2++;
		st = st->next;
	}
	if (l1 != 1 || l2 != 1)
		return (-1);
	return (0);
}

int		links_check(char *s, t_link *link, t_room *room)
{
	char	*r1;
	char	*r2;
	int		i;

	if (!(r1 = get_link_name(s, '-', &i)))
		return (-1);
	if (!(r2 = get_link_name(&s[i + 1], '\0', &i)))
	{
		free(r1);
		return (-1);
	}
	if (link_exist(link, r1, r2) || wrong_lname(room, r1, r2))
	{
		free(r1);
		free(r2);
		return (-1);
	}
	link = curr_link(link);
	link->r1 = r1;
	link->r2 = r2;
	return (1);
}
