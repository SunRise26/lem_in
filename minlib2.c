/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minlib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 22:15:12 by vveselov          #+#    #+#             */
/*   Updated: 2018/04/26 22:16:13 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_itoa(int n)
{
	int		ct;
	int		l;
	char	*ret;
	int		min;

	ct = 0;
	l = n;
	min = 1;
	while (++ct && l / 10 != 0)
		l /= 10;
	if (n < 0 && ++ct)
		min = -1;
	ret = (char *)malloc(sizeof(char) * (ct + 1));
	if (!ret)
		return (NULL);
	ret[ct--] = '\0';
	while (ct != -1)
	{
		ret[ct] = '0' + min * (n % 10);
		n /= 10;
		ct--;
	}
	if (min == -1)
		ret[0] = '-';
	return (ret);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		i++;
	write(1, s, i);
}
