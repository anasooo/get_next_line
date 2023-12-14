/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:52:56 by asodor            #+#    #+#             */
/*   Updated: 2023/12/10 21:22:37 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc((ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	while (s1[i] != '\0')
	{
		dup[i] = ((char *)s1)[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*b;
	int		j;

	if (!s1 || !s2)
		return (0);
	b = malloc((ft_strlen(s1) + 1) + ft_strlen(s2));
	if (!b)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		b[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		b[i] = s2[j];
		i++;
		j++;
	}
	b[i] = '\0';
	return (b);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
