/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:39:23 by ybutkov           #+#    #+#             */
/*   Updated: 2025/08/06 12:47:14 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_components_option.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_printf_c(t_option options, va_list args)
{
	unsigned char	ch;
	int				res_len;

	ch = (unsigned char)va_arg(args, int);
	res_len = 0;
	if (options.width > 0)
	{
		if (options.flags & MINUS)
			res_len += write(1, &ch, 1);
		while (--options.width > 0)
			res_len += write(1, " ", 1);
		if (!(options.flags & MINUS))
			res_len += write(1, &ch, 1);
		return (res_len);
	}
	return (write(1, &ch, 1));
}
