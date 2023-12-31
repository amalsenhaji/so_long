/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:14:12 by amsenhaj          #+#    #+#             */
/*   Updated: 2023/11/27 17:14:14 by amsenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_args(int ac, char **av)
{
	if (ac == 1)
	{
		printf("please entre map path !!\n");
		exit(0);
	}
	else if (ac > 2)
	{
		printf("too many arguments !!\n");
		exit(0);
	}
	else
	{
		if (ft_strcmp(".ber", ft_strstr(av[1], ".ber\0")))
		{
			printf("map format error !!\n");
			exit(0);
		}
	}
}

static void	ft_gameplay(t_vars *vars)
{
	ft_vars_init(vars);
	ft_fill_window(*vars);
	printf("width = %d\n", vars->width);
	mlx_key_hook(vars->win, ft_key_events, vars);
	mlx_hook(vars->win, 17, 0, ft_close, NULL);
	mlx_loop(vars->mlx);
}

int	main(int ac, char *av[])
{
	t_vars	vars;

	ft_check_args(ac, av);
	ft_check_valid_map(&vars, av[1]);
	ft_gameplay(&vars);
}
