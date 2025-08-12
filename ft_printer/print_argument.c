/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:26:15 by ybutkov           #+#    #+#             */
/*   Updated: 2025/08/06 13:02:33 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printer.h"
#include "libft.h"
#include "ft_constants.h"
#include <stdarg.h>

static unsigned int	get_flags(const char *str)
{
	unsigned int	flags;

	flags = 0;
	while (*str)
	{
		if (*str == MINUS_CHAR)
			flags |= MINUS;
		else if (*str == PLUS_CHAR)
			flags |= PLUS;
		else if (*str == SPACE_CHAR)
			flags |= SPACE;
		else if (*str == HASH_CHAR)
			flags |= HASH;
		else if (*str == ZERO_CHAR)
			flags |= ZERO;
		else
			break ;
		str++;
	}
	if (flags & MINUS && flags & ZERO)
		flags &= ~ZERO;
	if (flags & PLUS && flags & SPACE)
		flags &= ~SPACE;
	return (flags);
}

static int	get_current_number(const char **str)
{
	int	res;

	if (!ft_isdigit(**str))
		return (-1);
	res = 0;
	while (ft_isdigit(**str))
	{
		res = res * 10 + (**str - '0');
		(*str)++;
	}
	return (res);
}

static int	is_specifier(char ch)
{
	return (ft_strchr(SPECIFIERS, ch) != NULL);
}

static t_option	get_options(const char **str)
{
	t_option		options;
	int				is_precision;
	int				value;

	options = get_empty_options();
	options.flags |= get_flags(*str);
	is_precision = 0;
	while (*str && !is_specifier(**str))
	{
		value = get_current_number(str);
		if (value >= 0)
		{
			apply_value_for_options(&options, value, is_precision);
			is_precision = 0;
		}
		if (**str == '.')
		{
			options.is_precision = 1;
			is_precision = 1;
		}
		if ((is_specifier(**str)) || (**str == '\0'))
			break ;
		(*str)++;
	}
	return (options.specifier = **str, options);
}

void	get_and_print_arg(const char **str, va_list args, int *count)
{
	t_string_components	str_comp;
	t_option			options;
	int					len;

	options = get_options(str);
	str_comp = init_string_components();
	len = 0;
	set_alignment(&str_comp, options);
	if (options.specifier == 's')
		len = ft_printf_s(options, str_comp, args);
	else if (options.specifier == '%')
		len = ft_printf_proc(options, str_comp);
	else if (options.specifier == 'c')
		len = ft_printf_c(options, args);
	else if (options.specifier == 'p')
		len = ft_printf_p(options, str_comp, args);
	else if (options.specifier == 'd' || options.specifier == 'i')
		len = ft_printf_d(options, str_comp, args);
	else if (options.specifier == 'u')
		len = ft_printf_u(options, str_comp, args);
	else if (options.specifier == 'x' || options.specifier == 'X')
		len = ft_printf_x(options, str_comp, args);
	if (len == -1)
		*count = 0;
	*count += len;
}
