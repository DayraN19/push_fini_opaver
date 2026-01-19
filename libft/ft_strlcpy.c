/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgranier <bgranier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:23:30 by bgranier          #+#    #+#             */
/*   Updated: 2025/11/13 15:06:47 by bgranier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	cur;

	if (size == 0)
		return (ft_strlen(src));
	cur = 0;
	while (src[cur] && cur < (size - 1))
	{
		dst[cur] = src[cur];
		cur++;
	}
	dst[cur] = 0;
	return (ft_strlen(src));
}

/* int main(void)
{
	char src[] = "bas";
	char dest[] = "";
	
	ft_strlcpy(dest , src, 0);
	
	printf("src = %s\n", src);
	printf("dest = %s\n", dest);

	return (0);
} */
