/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:16:44 by ybutkov           #+#    #+#             */
/*   Updated: 2025/08/05 13:59:30 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_components_option.h"

t_option	get_empty_options(void)
{
	t_option	options;

	options.flags = 0;
	options.width = -1;
	options.precision = 0;
	options.is_precision = 0;
	options.specifier = '\0';
	return (options);
}

void	apply_value_for_options(t_option *options, int value, int is_precision)
{
	if (value >= 0)
	{
		if (!is_precision)
			options->width = value;
		else
			options->precision = value;
	}
}
