/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgranier <bgranier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:26:00 by bgranier          #+#    #+#             */
/*   Updated: 2025/11/06 14:11:01 by bgranier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst2;
	unsigned char	*src2;

	dst2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (src < dest)
	{
		src2 = src2 + n - 1;
		dst2 = dst2 + n - 1;
		while (n--)
			*dst2-- = *src2--;
	}
	else if (src >= dest)
	{
		while (n--)
			*dst2++ = *src2++;
	}
	return (dest);
}

/*int main()
{
    char str1[] = "Hell, world!";
    char str2[20];

    ft_memmove(str2, str1, strlen(str1) + 1);

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    return 0;
}*/