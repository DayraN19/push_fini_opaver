/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgranier <bgranier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:17:02 by bgranier          #+#    #+#             */
/*   Updated: 2025/11/06 14:11:09 by bgranier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	int		len;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/* int main(void)
{
	char *src;
	char *dup;

	src = "Hello";
	dup = ft_strdup(src);
	if(!dup)
		return (1);
	printf ("%s", ft_strdup("hello"));

	return (0);
} */