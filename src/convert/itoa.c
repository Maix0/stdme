/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:05:46 by maiboyer          #+#    #+#             */
/*   Updated: 2023/11/10 14:56:42 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem/memset.h"
#include "ft/num/itoa.h"
#include "ft/string/strdup.h"
#include <stdlib.h>

static void	me_itoa_inner(t_u64 nb, t_str out)
{
	t_i32	modulus;
	t_bool	need_print;
	char	c;
	t_usize	idx;

	need_print = FALSE;
	modulus = 1000000000;
	idx = 0;
	while (modulus)
	{
		c = (char)(nb / modulus) + '0';
		if (c != '0' || need_print)
		{
			out[idx++] = c;
			need_print = TRUE;
		}
		nb = nb % modulus;
		modulus /= 10;
	}
}

t_str	me_itoa(t_i32 nb)
{
	char	out[12];
	t_u64	n;

	n = (t_u64)nb;
	me_memset(out, 0, 12);
	if (nb < 0)
	{
		out[0] = '-';
		me_itoa_inner(-n, out + 1);
	}
	else if (nb == 0)
		out[0] = '0';
	else
		me_itoa_inner(n, out);
	return (me_strdup(out));
}
/*R
int	main(void)
{
	me_putnbr(-2147483648);
	write(1, "\n", 1);
	me_putnbr(0);
	write(1, "\n", 1);
	me_putnbr(12345);
	return (0);
}
R*/
