/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:46:21 by vveselov          #+#    #+#             */
/*   Updated: 2018/04/27 09:20:31 by vveselov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LEM_IN_H
# define __LEM_IN_H
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct		s_room
{
	char			*name;
	int				coord[2];
	char			visited;
	int				type;
	int				num;
	int				dist;
	struct s_room	*next;
}					t_room;

typedef struct		s_link
{
	char			*r1;
	char			*r2;
	struct s_link	*next;
}					t_link;

typedef struct		s_way
{
	char			*name;
	int				ant;
	struct s_way	*next;
}					t_way;

typedef struct		s_ways
{
	int				dist;
	struct s_way	*way;
	struct s_ways	*next;
}					t_ways;

void				free_all(t_room *room, t_link *link, t_ways *ways,
								char *out);
void				ants_out(t_room *room, t_ways *ways, int ants_n,
								char *out);
int					fin_ch(t_room *room, t_link *link);
int					ants_num(char *s, int *n);
int					input_rooms(t_room *room, t_link *link,
								char *l, char **out);
int					input_links(t_room *room, t_link *link, char *l);
int					check_input(int *ants_n, t_room *room,
								t_link *link, char **out);
t_room				*new_room(void);
void				del_last_nameless_room(t_room *room);
t_link				*new_link(void);
void				del_link(t_link *link);
void				del_room(t_room *room);
int					rooms_check(char **s, t_room *room, char **out);
int					room_type(char **s, char **out, t_room *room, int *type);
int					room_st_fin(t_room *room, int sw);
int					room_exist(t_room *room);
int					get_name_coords(char *s, t_room *room, int type);
t_link				*curr_link(t_link *link);
char				*get_link_name(char *s, char sp, int *i);
int					link_exist(t_link *link, char *r1, char *r2);
int					wrong_lname(t_room *room, char *r1, char *r2);
int					links_check(char *s, t_link *link, t_room *room);
int					st_end(t_room *st, t_room *end, t_link *link, t_ways *ways);
void				st_next_cmp(int dist_num[2], t_room *room,
								t_link *link, t_room *st);
void				st_cmp(int dist_num[2], t_room *room,
								t_link *link, t_room *st);
int					r_num(t_room *room, char *name);
void				fill_matrix(int **mx, t_room *room, t_link *link);
int					room_num(t_room *room);
int					**matrix(int size);
void				del_matrix(int **mx, int size);
void				level_up(int **q, int **q1, int size);
void				add_dist(int **mx, int size, int *q, t_room *room);
void				mx_null(int **mx, int size);
void				dist_null(t_room *room);
t_ways				*bfs(t_room *room, t_link *link);
void				add_new_way(int dist_num[2], t_room *room,
								t_link *link, t_ways *ways);
int					new_w(t_ways *ways, t_room *room, t_link *link);
void				queue_in(int *q, int num);
t_room				*queue_out(int *q, t_room *room);
int					*queue(int size);
t_room				*get_type_room(int type, t_room *room);
t_room				*get_num_room(int num, t_room *room);
t_room				*get_mx_room(int **mx, int size, int num, t_room *room);
t_room				*get_name_room(char *name, t_room *room);
t_way				*new_way(char *name);
t_ways				*new_ways(void);
t_ways				*next_ways(t_ways *ways);
void				del_way(t_way *way);
void				del_ways(t_ways *ways);
void				ans_wr(int i, char *s, char fl);
void				all_in(int ants, char *end);
int					move_up(int dist, t_way *way, t_room *room, int j);
int					ways_up(t_ways *ways, t_room *room);
void				lets_go(int ants, t_ways *ways,
								t_room *room, t_ways *begin);
void				ft_putendl(char *s);
int					ft_strcmp(char *s1, char *s2);
int					ft_atoi_spec(char *str, char stop);
char				*ft_concat(char	*s1, char *s2);
char				*ft_strdup(char *s);
char				*ft_itoa(int n);
void				ft_putstr(char *s);

#endif
