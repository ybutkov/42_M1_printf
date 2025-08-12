/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_constants.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:53:25 by ybutkov           #+#    #+#             */
/*   Updated: 2025/08/06 14:21:41 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONSTANTS_H
# define FT_CONSTANTS_H

# define SPECIFIERS "cspdiuxX%"
# define HEX_BASE_SIZE 16
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"
# define SPACE_CHAR ' '
# define ZERO_CHAR '0'
# define PLUS_CHAR '+'
# define MINUS_CHAR '-'
# define HASH_CHAR '#'
# define PERCENT_CHAR '%'
# define PERCENT_STR "%"
# define HEX_LOW_PREFIX "0x"
# define HEX_HIGH_PREFIX "0X"
# define NULL_STRING "(null)"

// OS-specific definitions
# if defined(__APPLE__)
#  define NULL_POINTER "0"
#  define SHIFT_FOR_ALONE_PERC 1
# elif defined(__linux__)
#  define NULL_POINTER "(nil)"
#  define SHIFT_FOR_ALONE_PERC 0
# endif

#endif