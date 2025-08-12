/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_n_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:09:27 by ybutkov           #+#    #+#             */
/*   Updated: 2025/08/02 18:09:42 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_n_char(char ch, int n)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (n--)
	{
		i = write(1, &ch, 1);
		if (i == -1)
			return (-1);
		total += i;
	}
	return (total);
}
