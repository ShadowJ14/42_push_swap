/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:38:02 by lprates           #+#    #+#             */
/*   Updated: 2021/09/25 18:41:10 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	size_t			j;

	i = n;
	j = -1;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
		while (i-- > 0)
			((char *)dest)[i] = ((const char *)src)[i];
	else
		while (++j < n)
			((char *)dest)[j] = ((const char *)src)[j];
	return (dest);
}
