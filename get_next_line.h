/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:46:05 by vveselov          #+#    #+#             */
/*   Updated: 2017/12/19 19:08:35 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 32

int				get_next_line(const int fd, char **line);

typedef struct	s_fd
{
	int			fd;
	int			rd;
	char		*str;
	struct s_fd	*next;
}				t_fd;

#endif
