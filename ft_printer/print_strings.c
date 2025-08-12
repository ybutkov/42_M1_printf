/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:46:43 by ybutkov           #+#    #+#             */
/*   Updated: 2025/08/06 12:54:42 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_components_option.h"
#include "ft_constants.h"
#include "ft_converter.h"
#include "ft_math.h"
#include "ft_printer.h"
#include "libft.h"
#include <stdarg.h>

#ifdef __linux__

static int	check_null_string(t_string_components str_comp, int str_len)
{
	if (!ft_strncmp(str_comp.root, NULL_STRING, 7)
		&& str_comp.root_len > str_len)
		str_len = 0;
	return (str_len);
}

#elif defined(__APPLE__)

static int	check_null_string(t_string_components str_comp, int str_len)
{
	(void)str_comp;
	return (str_len);
}

#endif

static int	ft_print_string(t_option options, t_string_components str_comp)
{
	int	count;
	int	str_len;

	str_comp.root_len = ft_strlen(str_comp.root);
	if (options.is_precision && options.precision < str_comp.root_len)
		str_len = options.precision;
	else
		str_len = str_comp.root_len;
	str_len = check_null_string(str_comp, str_len);
	str_comp.total_len = ft_max(options.width, str_len);
	str_comp.len_root_to_print = str_len;
	str_comp.spaces_amount = str_comp.total_len - str_len;
	count = print_formatted_data(str_comp);
	return (count);
}

int	ft_printf_proc(t_option options, t_string_components str_comp)
{
	str_comp.root = PERCENT_STR;
	return (ft_print_string(options, str_comp));
}

int	ft_printf_s(t_option options, t_string_components str_comp, va_list args)
{
	str_comp.root = va_arg(args, char *);
	if (str_comp.root == NULL)
		str_comp.root = NULL_STRING;
	return (ft_print_string(options, str_comp));
}
