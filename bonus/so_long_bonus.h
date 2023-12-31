/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:13:39 by amsenhaj          #+#    #+#             */
/*   Updated: 2023/11/27 17:13:40 by amsenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_vars
{
	char	**map;
	int		length;
	int		width;
	int		collect;
	int		exit;
	int		cp;
	int		game_over;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_collect[8];
	void	*img_floor;
	void	*img_enemy;
	void	*img_exit[6];
	void	*img_player;
}	t_vars;

//mini utils
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strstr(char *str, char *to_find);
char	*get_next_line(int fd);
char	*ft_itoa(int n);

//map check
void	ft_check_width(t_vars *vars);
void	ft_check_valid(char **map);
void	ft_check_walls(t_vars *vars);
void	ft_process_map(t_vars *vars, char *path);
void	ft_check_args(int ac, char **av);
void	ft_check_valid_map(t_vars *vars, char *path);

//init
void	ft_vars_init(t_vars *vars);
void	ft_fill_window(t_vars vars);

//keypress
int		ft_key_events(int keypress, t_vars *vars);

//movements
void	ft_collect_exit(t_vars *vars, int x, int y, int move);
void	get_player_pos(char **map, int *x, int *y);
void	ft_dead(t_vars *vars, char c);
int		ft_valid_move(t_vars *vars, int x, int y);
void	ft_gameover(t_vars *vars);

//anim
int		anim(t_vars *vars);
void	ft_anim_enemy(t_vars *vars);

#endif
