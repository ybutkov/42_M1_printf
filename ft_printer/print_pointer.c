/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:34:06 by ybutkov           #+#    #+#             */
/*   Updated: 2025/08/06 13:13:00 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_components_option.h"
#include "ft_constants.h"
#include "ft_converter.h"
#include "ft_math.h"
#include "ft_printer.h"
#include "libft.h"
#include <stdarg.h>

#ifdef __APPLE__

void	set_hex_prefix(t_string_components *str_comp)
{
	str_comp->pre_root = HEX_LOW_PREFIX;
	str_comp->pre_root_len = 2;
}
#elif defined(__linux__)

void	set_hex_prefix(t_string_components *str_comp)
{
	(void)str_comp;
}
#endif

static int	get_pointer_to_str_comp(t_string_components *str_comp, void *p)
{
	if (p == NULL)
	{
		str_comp->root = NULL_POINTER;
		str_comp->root_len = ft_strlen(str_comp->root);
		set_hex_prefix(str_comp);
		return (1);
	}
	str_comp->root = p_to_hex(p, HEX_BASE_LOWER, HEX_BASE_SIZE);
	if (!str_comp->root)
		return (0);
	str_comp->root_len = ft_strlen(str_comp->root);
	str_comp->pre_root = HEX_LOW_PREFIX;
	str_comp->pre_root_len = 2;
	return (1);
}

int	ft_printf_p(t_option options, t_string_components str_comp, va_list args)
{
	void	*p;
	int		count;
	int		str_len;

	p = va_arg(args, void *);
	if (get_pointer_to_str_comp(&str_comp, p) == 0)
		return (-1);
	if (options.is_precision && options.precision > str_comp.root_len)
		str_len = options.precision;
	else
		str_len = str_comp.root_len;
	str_comp.total_len = ft_max(options.width, str_len + str_comp.pre_root_len);
	if (options.flags & ZERO && !options.is_precision)
		str_len = str_comp.total_len;
	str_comp.spaces_amount = str_comp.total_len - str_len
		- str_comp.pre_root_len;
	str_comp.zeros_amount = str_len - str_comp.root_len;
	str_comp.len_root_to_print = str_comp.root_len;
	count = print_formatted_data(str_comp);
	if (p != NULL)
		free(str_comp.root);
	return (count);
}
