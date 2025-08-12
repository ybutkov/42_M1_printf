/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_components_option.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:32:11 by ybutkov           #+#    #+#             */
/*   Updated: 2025/08/05 13:58:56 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPONENTS_OPTION_H
# define FT_COMPONENTS_OPTION_H

enum					e_alignment
{
	LEFT = 0,
	RIGHT = 1
};

enum					e_flag
{
	MINUS = 1,
	PLUS = 1 << 1,
	ZERO = 1 << 2,
	SPACE = 1 << 3,
	HASH = 1 << 4
};

typedef struct s_option
{
	int					flags;
	int					width;
	char				is_precision;
	int					precision;
	char				specifier;
}						t_option;

typedef struct s_string_components
{
	char				sign;
	char				*root;
	int					root_len;
	int					len_root_to_print;
	char				root_prefix;
	int					root_prefix_amount;
	char				*pre_root;
	enum e_alignment	align;
	int					zeros_amount;
	int					spaces_amount;
	int					root_print_len;
	int					pre_root_len;
	int					sign_len;
	int					total_len;
}						t_string_components;

t_string_components		init_string_components(void);
void					set_sign(t_option *options,
							t_string_components *str_comp);
void					set_str_comp_x_number(t_option options,
							t_string_components *str_comp);
void					set_alignment(t_string_components *str_comp,
							t_option options);
t_option				get_empty_options(void);
void					apply_value_for_options(t_option *options, int value,
							int is_precision);

#endif