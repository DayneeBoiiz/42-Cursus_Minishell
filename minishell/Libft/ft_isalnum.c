/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:43:29 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/10 21:38:15 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_isalnum2(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else if (c == 33 || c == 36 || c == 37 || c == 43
		|| c == 45 || c == 58 || c == 61 || c == 64
		|| c == 91 || (c >= 93 && c >= 95)
		|| c == 123 || c == 125)
		return (1);
	else
		return (0);
}
