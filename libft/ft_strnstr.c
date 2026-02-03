/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgranier <bgranier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:23:47 by bgranier          #+#    #+#             */
/*   Updated: 2026/01/20 13:35:04 by bgranier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hayst, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	if (*needle == '\0')
		return ((char *)hayst);
	i = 0;
	while (hayst[i] != '\0' && i < len)
	{
		if (hayst[i] == needle[0])
		{
			j = 0;
			while (needle[j] && hayst[i + j] && i + j < len
				&& hayst[i + j] == needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)hayst + i);
		}
		i++;
	}
	return (0);
}

/*int main()
{
    const char *largestring = "Foo Bar Baz";
    const char *smallstring = "Bar";
    char *ptr;

    ptr = strnstr(largestring, smallstring, 4);
}*/