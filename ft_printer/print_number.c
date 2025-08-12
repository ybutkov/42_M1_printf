/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:05:13 by ybutkov           #+#    #+#             */
/*   Updated: 2025/08/05 18:45:36 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_components_option.h"
#include "ft_constants.h"
#include "ft_converter.h"
#include "ft_printer.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

static int	print_number(t_option options, t_string_components str_comp)
{
	int	count;

	set_str_comp_x_number(options, &str_comp);
	count = print_formatted_data(str_comp);
	if (str_comp.root != NULL && ft_strncmp(str_comp.root, "", 1) != 0)
		free(str_comp.root);
	return (count);
}

int	ft_printf_d(t_option options, t_string_components str_comp, va_list args)
{
	int	int_value;

	int_value = va_arg(args, int);
	if (int_value == 0 && options.is_precision && options.precision == 0)
		str_comp.root = "";
	else if (int_value < 0)
	{
		if (int_value == -2147483648)
			str_comp.root = ft_strdup("2147483648");
		else
			str_comp.root = ft_itoa(-int_value);
	}
	else
		str_comp.root = ft_itoa(int_value);
	if (!str_comp.root)
		return (-1);
	str_comp.root_len = ft_strlen(str_comp.root);
	if (int_value < 0)
		str_comp.sign = MINUS_CHAR;
	return (print_number(options, str_comp));
}

int	ft_printf_u(t_option options, t_string_components str_comp, va_list args)
{
	unsigned int	unint_value;

	unint_value = va_arg(args, unsigned int);
	if (unint_value == 0 && options.is_precision && options.precision == 0)
		str_comp.root = "";
	else
		str_comp.root = ft_ultoa(unint_value);
	if (!str_comp.root)
		return (-1);
	return (print_number(options, str_comp));
}

static void	convert_value_to_hex(t_option options,
		t_string_components *str_comp, unsigned int v)
{
	if (v == 0 && options.is_precision && options.precision == 0)
		str_comp->root = "";
	else if (v == 0)
		str_comp->root = ft_strdup("0");
	else
	{
		if (options.specifier == 'x')
			str_comp->root = unlong_to_hex(v, HEX_BASE_LOWER, HEX_BASE_SIZE);
		else
			str_comp->root = unlong_to_hex(v, HEX_BASE_UPPER, HEX_BASE_SIZE);
		if (v != 0 && options.flags & HASH)
		{
			if (options.specifier == 'x')
				str_comp->pre_root = HEX_LOW_PREFIX;
			if (options.specifier == 'X')
				str_comp->pre_root = HEX_HIGH_PREFIX;
		}
	}
}

int	ft_printf_x(t_option options, t_string_components str_comp, va_list args)
{
	unsigned int	value;
	int				count;

	value = (unsigned int)va_arg(args, int);
	convert_value_to_hex(options, &str_comp, value);
	if (!str_comp.root)
		return (-1);
	str_comp.sign = '\0';
	set_str_comp_x_number(options, &str_comp);
	count = print_formatted_data(str_comp);
	if (ft_strncmp(str_comp.root, "", 1) != 0)
		free(str_comp.root);
	return (count);
}
