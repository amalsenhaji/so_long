/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:13:21 by amsenhaj          #+#    #+#             */
/*   Updated: 2023/11/27 17:13:23 by amsenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_alloc(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*rst;
	int				size;
	unsigned int	nb;

	size = ft_alloc(n) + 1;
	rst = (char *)malloc(size * sizeof(char));
	if (!rst)
		return (NULL);
	if (n < 0)
		nb = -n;
	else
		nb = n;
	rst[--size] = 0;
	while (--size >= 0 && nb)
	{
		rst[size] = '0' + nb % 10;
		nb /= 10;
	}
	if (n < 0)
		rst[0] = '-';
	if (n == 0)
		rst[0] = '0';
	return (rst);
}
