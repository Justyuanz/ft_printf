/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:16:45 by jinzhang          #+#    #+#             */
/*   Updated: 2025/04/28 20:30:25 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// check input validation
// count words using delimiter, then we have indexes of the array
// like argv, the last in the array is NULL
// count size for each element
static int	count_words(char const *s, char c)
{
	size_t	len;
	size_t	i;
	int		word;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static size_t	word_len(char const *s, char c)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (c == s[i])
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void	*ft_free(char **arr, int index)
{
	while (index >= 0)
	{
		free(arr[index]);
		index--;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	totalwords;
	size_t	i;
	size_t	j;
	size_t	wordlen;

	i = 0;
	j = 0;
	totalwords = count_words(s, c);
	arr = malloc((totalwords + 1) * sizeof(char *));
	if (!s || !arr)
		return (NULL);
	while (i < totalwords)
	{
		while (s[j] == c)
			j++;
		wordlen = word_len(s + j, c);
		arr[i] = ft_substr(s + j, 0, wordlen);
		j += wordlen;
		if (!arr[i])
			return (ft_free(arr, i));
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
