/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgranier <bgranier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:18:57 by bgranier          #+#    #+#             */
/*   Updated: 2025/11/10 15:13:12 by bgranier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	k;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (size < len_dst)
		len_src += size;
	else
		len_src += len_dst;
	k = 0;
	while (src[k] != '\0' && (len_dst + k) < size - 1)
	{
		dst[len_dst + k] = src[k];
		k++;
	}
	dst[len_dst + k] = '\0';
	return (len_src);
}

/* int	main(void)
{
	char src[] = "";
	char dest[50] = "";
	
	ft_strncat(dest , src, 2);
	
	printf("src = %s\n", src);
	printf("dest = %s\n", dest);

	return (0);
} */
