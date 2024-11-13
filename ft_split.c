/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitormar <aitormar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:03:02 by aitormar          #+#    #+#             */
/*   Updated: 2024/09/18 13:26:57 by aitormar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(const char *s, char c)
{
	int	cont;
	int	trigger;
	int	i;

	cont = 0;
	trigger = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && trigger != 1)
		{
			trigger = 1;
			cont++;
		}
		else if (s[i] == c)
			trigger = 0;
		i++;
	}
	return (cont);
}

char	*ft_getword(const char *s, char c)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i + j] && s[i + j] != c)
		j++;
	word = ft_substr(s, i, j);
	return (word);
}

void	ft_free(char **res, int j)
{
	while (j > 0)
	{
		free(res[j - 1]);
		j--;
	}
	free(res);
}

char	**ft_fillsplit(char const *s, char c, char **res, int wordquantity)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (wordquantity > 0)
	{
		while (s[i] == c)
			i++;
		res[j] = ft_getword(s + i, c);
		if (!res[j])
		{
			ft_free(res, j);
			return (NULL);
		}
		j++;
		while (s[i] && s[i] != c)
			i++;
		wordquantity--;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		wordquantity;
	char	**res;

	if (!s)
		return (NULL);
	wordquantity = ft_wordcount(s, c);
	res = ft_calloc(sizeof(char *), wordquantity + 1);
	if (!res)
		return (NULL);
	res = ft_fillsplit(s, c, res, wordquantity);
	return (res);
}

// int main(void)
// {
// 	char	**pr;
// 	int		i;
// 	char	*str = "El mundo esta loco, encima me pones estos colores más feos y horribles.";

// 	pr = ft_split(str, ' ');

// 	i = 0;
// 	while (pr[i])
// 	{
// 		printf("%s\n", pr[i]);
// 		i += 1;
// 	}

// 	i = 0;
// 	while (pr[i])
// 	{
// 		free(pr[i]);
// 		i += 1;
// 	}
// 	free(pr);
// }
