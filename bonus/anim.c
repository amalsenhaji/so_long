/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:30:03 by amsenhaj          #+#    #+#             */
/*   Updated: 2023/11/27 16:30:05 by amsenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_anim_collect(t_vars *vars, int k)
{
	int	i;
	int	j;

	i = 0;
	if (!vars->collect)
		return ;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx,
					vars->win, vars->img_collect[k], 50 * j, 50 * i);
			j++;
		}
		i++;
	}
}

static void	ft_anim_door(t_vars *vars, int k)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx,
					vars->win, vars->img_exit[k], 50 * j, 50 * i);
			j++;
		}
		i++;
	}
}

static void	ft_ft(t_vars *vars, int *i)
{
	if (*i == 5)
	{
		ft_anim_enemy(vars);
		*i = 0;
	}
}

int	anim(t_vars *vars)
{
	static int	k;
	static int	i;
	static int	j;
	static int	l;

	if (l == 600)
	{
		ft_anim_collect(vars, k);
		ft_ft(vars, &i);
		k++;
		if (k == 8)
			k = 0;
		if (vars->exit == 1)
		{
			if (j < 6)
				ft_anim_door(vars, j);
			else
				vars->exit = 0;
			j++;
		}
		i++;
		l = 0;
	}
	l++;
	return (0);
}
