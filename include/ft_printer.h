/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:04:50 by ybutkov           #+#    #+#             */
/*   Updated: 2025/08/12 14:01:00 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTER_H
# define FT_PRINTER_H

# include "ft_components_option.h"
# include <stdarg.h>

int		ft_printf_s(t_option options, t_string_components str_comp,
			va_list args);
int		ft_printf_c(t_option options, va_list args);
int		ft_printf_p(t_option options, t_string_components str_comp,
			va_list args);
int		ft_printf_d(t_option options, t_string_components str_comp,
			va_list args);
int		ft_printf_u(t_option options, t_string_components str_comp,
			va_list args);
int		ft_printf_x(t_option options, t_string_components str_comp,
			va_list args);
int		ft_printf_proc(t_option options, t_string_components str_comp);
int		print_n_char(char ch, int n);
int		print_formatted_data(t_string_components str_comp);
void	get_and_print_arg(const char **str, va_list args, int *count);

#endif
