/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:01:32 by ybutkov           #+#    #+#             */
/*   Updated: 2025/08/05 14:00:58 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	nbr_len(unsigned long nbr, int base_size)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base_size;
		len++;
	}
	return (len);
}

char	*unlong_to_hex(unsigned long nbr, char *base, unsigned int base_size)
{
	char		*hex;
	int			i;
	int			len;

	len = nbr_len(nbr, base_size);
	hex = malloc((len + 1) * sizeof(char));
	if (!hex)
		return (NULL);
	i = 0;
	if (nbr == 0)
		hex[0] = base[0];
	while (nbr > 0)
	{
		hex[len - i - 1] = base[nbr % base_size];
		nbr /= base_size;
		i++;
	}
	hex[len] = '\0';
	return (hex);
}

char	*p_to_hex(void *p, char *base, unsigned int base_size)
{
	return (unlong_to_hex((long long int)p, base, base_size));
}
