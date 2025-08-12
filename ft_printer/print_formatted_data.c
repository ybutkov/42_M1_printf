/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formatted_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:15:32 by ybutkov           #+#    #+#             */
/*   Updated: 2025/08/04 18:35:08 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printer.h"
#include <unistd.h>

int	print_formatted_data(t_string_components str_comp)
{
	int	res;

	res = 0;
	if (str_comp.align == LEFT)
	{
		res += write(1, &str_comp.sign, str_comp.sign_len);
		res += write(1, str_comp.pre_root, str_comp.pre_root_len);
		res += print_n_char('0', str_comp.zeros_amount);
		res += write(1, str_comp.root, str_comp.len_root_to_print);
		res += print_n_char(' ', str_comp.spaces_amount);
	}
	else
	{
		res += print_n_char(' ', str_comp.spaces_amount);
		res += write(1, &str_comp.sign, str_comp.sign_len);
		res += write(1, str_comp.pre_root, str_comp.pre_root_len);
		res += print_n_char('0', str_comp.zeros_amount);
		res += write(1, str_comp.root, str_comp.len_root_to_print);
	}
	return (res);
}
