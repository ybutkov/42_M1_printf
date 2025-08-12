/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:49:00 by ybutkov           #+#    #+#             */
/*   Updated: 2025/08/12 14:00:52 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERTER_H
# define FT_CONVERTER_H

char			*p_to_hex(void *p, char *base, unsigned int base_size);
char			*ft_ultoa(unsigned long n);
char			*unlong_to_hex(unsigned long nbr, char *base,
					unsigned int base_size);

#endif