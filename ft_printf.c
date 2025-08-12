/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:25:52 by ybutkov           #+#    #+#             */
/*   Updated: 2025/08/06 14:22:10 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printer.h"
#include "ft_constants.h"
#include <unistd.h>
#include <stdarg.h>

static const char	*find_next_percent_char(const char *str)
{
	while (*str && *str != '%')
		str++;
	return (str);
}

static void	print_if_no_specifier(const char *s_cur, const char *s, int *count)
{
	if (*count != -1 && *s == '\0')
		*count += write(1, s_cur, s - s_cur);
}

int	ft_printf(const char *s, ...)
{
	int			count;
	int			n;
	va_list		args;
	const char	*s_cur;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		s_cur = find_next_percent_char(s);
		n = write(1, s, s_cur - s);
		if (n == -1)
			return (-1);
		count += n;
		s = s_cur + 1;
		if (*s_cur == '\0' || *s == '\0')
			break ;
		get_and_print_arg(&s, args, &count);
		print_if_no_specifier(s_cur + SHIFT_FOR_ALONE_PERC, s, &count);
		if (count == -1 || *s == '\0')
			break ;
		s = s + 1;
	}
	va_end(args);
	return (count);
}
