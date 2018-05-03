/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:51:05 by vveselov          #+#    #+#             */
/*   Updated: 2018/04/26 22:06:04 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	queue_in(int *q, int num)
{
	q[++q[0]] = num;
	q[2]++;
}

t_room	*queue_out(int *q, t_room *room)
{
	q[2]--;
	return (get_num_room(q[q[1]++], room));
}

int		*queue(int size)
{
	int		*q;

	q = (int *)malloc(sizeof(int) * size + 3);
	q[0] = 2;
	q[1] = 3;
	q[2] = 0;
	return (q);
}
