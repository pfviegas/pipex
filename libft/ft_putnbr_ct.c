/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:30:37 by pviegas           #+#    #+#             */
/*   Updated: 2023/07/27 11:22:25 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_ct(int n, size_t *counter)
{
	char	c;
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		write(2, "-", 1);
		nb = -nb;
		(*counter)++;
	}
	if (nb >= 10)
	{
		ft_putnbr_ct(nb / 10, counter);
	}
	c = (char)(nb % 10 + '0');
	write(2, &c, 1);
	(*counter)++;
}
