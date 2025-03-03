/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitor <aitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:53:56 by aitor             #+#    #+#             */
/*   Updated: 2025/03/03 11:06:12 by aitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_gnl(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char )c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char )c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*res;
	int		s1len;
	int		s2len;
	int		i;

	s1len = 0;
	s2len = 0;
	if (s1)
		s1len = ft_strlen(s1);
	if (s2)
		s2len = ft_strlen(s2);
	res = ft_calloc(sizeof(char), (s1len + s2len + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		res[i] = s1[i];
	i = -1;
	while (s2 && s2[++i])
		res[s1len + i] = s2[i];
	res[s1len + s2len] = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	void	*res;
	char	*str;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	str = (char *)res;
	i = 0;
	while (i < nmemb * size)
	{
		str[i] = '\0';
		i++;
	}
	return (res);
}

void	*ft_free_and_null(void *ptr)
{
	free(ptr);
	return (NULL);
}
