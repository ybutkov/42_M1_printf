/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_components_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:30:54 by ybutkov           #+#    #+#             */
/*   Updated: 2025/08/05 18:55:14 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printer.h"
#include "libft.h"
#include "ft_components_option.h"
#include "ft_math.h"
#include "ft_constants.h"

void	set_sign(t_option *options, t_string_components *str_comp)
{
	if (!ft_strchr("di", options->specifier))
		return ;
	if (str_comp->sign == '\0' && options->flags & PLUS)
		str_comp->sign = PLUS_CHAR;
	else if (str_comp->sign == '\0' && options->flags & SPACE)
		str_comp->sign = SPACE_CHAR;
	if (str_comp->sign)
		str_comp->sign_len = 1;
}

void	set_str_comp_x_number(t_option options, t_string_components *str_comp)
{
	int	str_len;

	str_comp->root_len = ft_strlen(str_comp->root);
	if (str_comp->pre_root)
		str_comp->pre_root_len = ft_strlen(str_comp->pre_root);
	set_sign(&options, str_comp);
	if (options.is_precision && options.precision > str_comp->root_len)
		str_len = options.precision;
	else
		str_len = str_comp->root_len;
	str_comp->total_len = ft_max(options.width, str_len + str_comp->sign_len
			+ str_comp->pre_root_len);
	if (options.flags & ZERO && !options.is_precision)
		str_len = str_comp->total_len - str_comp->sign_len
			- str_comp->pre_root_len;
	str_comp->spaces_amount = str_comp->total_len - str_len - str_comp->sign_len
		- str_comp->pre_root_len;
	str_comp->zeros_amount = str_len - str_comp->root_len;
	str_comp->len_root_to_print = str_comp->root_len;
}

t_string_components	init_string_components(void)
{
	t_string_components	string_components;

	string_components.sign = '\0';
	string_components.root = NULL;
	string_components.len_root_to_print = 0;
	string_components.len_root_to_print = 0;
	string_components.root_prefix = '\0';
	string_components.root_prefix_amount = 0;
	string_components.pre_root = NULL;
	string_components.align = RIGHT;
	string_components.total_len = 0;
	string_components.zeros_amount = 0;
	string_components.spaces_amount = 0;
	string_components.root_print_len = 0;
	string_components.pre_root_len = 0;
	string_components.root_len = 0;
	string_components.sign_len = 0;
	return (string_components);
}

void	set_alignment(t_string_components *str_comp, t_option options)
{
	if (options.flags & MINUS)
		str_comp->align = LEFT;
	else
		str_comp->align = RIGHT;
}
