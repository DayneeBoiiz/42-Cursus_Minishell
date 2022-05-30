/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:09:47 by zkasmi            #+#    #+#             */
/*   Updated: 2021/11/29 20:09:59 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_perror.h"

int	ft_putnbr_u(unsigned int nb, int *len)
{
	unsigned int	num;

	num = nb;
	if (num < 0)
	{
		ft_putchar('-');
		(*len)++;
		num = num * (-1);
	}
	if (num >= 0 && num <= 9)
	{
		ft_putchar(num + '0');
		(*len)++;
	}
	if (num >= 10)
	{
		ft_putnbr_u(num / 10, len);
		ft_putchar((num % 10) + '0');
		(*len)++;
	}
	return (0);
}
