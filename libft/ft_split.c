/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:31:18 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/11 15:37:34 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_n_words(char const *s1, char c)
{
	int	i;
	int	in_word;
	int	wc;

	i = 0;
	in_word = 0;
	wc = 0;
	while (s1[i])
	{
		if (s1[i] != c && in_word == 0)
		{
			in_word = 1;
			wc++;
		}
		if (s1[i] == c)
			in_word = 0;
		i++;
	}
	return (wc);
}

static char const	*save_word(char const *s, char **wloc, char sep)
{
	char	*word;
	int		i;
	int		len_word;

	len_word = 0;
	i = 0;
	while (s[len_word] != sep && (s[len_word]))
		len_word++;
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	while (i < len_word)
	{
		word[i] = s[i];
		i++;
	}
	word[len_word] = '\0';
	*wloc = word;
	return (&s[len_word]);
}

static int	cleaning(char **outp)
{
	int	i;

	i = 0;
	while (outp[i] != NULL)
	{
		free(outp[i]);
		i++;
	}
	free(outp);
	return (-1);
}

static int	run_string(char const *s,	char sep, char **outp)
{
	int	i;
	int	in_word;
	int	cage;

	cage = 0;
	in_word = 0;
	i = 0;
	while (*s)
	{
		if (*s != sep && in_word == 0)
		{
			in_word = 1;
			s = save_word(s, &outp[cage++], sep);
			if (s == NULL)
				return (cleaning(outp));
		}
		if (*s == sep)
			in_word = 0;
		if (*s != '\0')
			s++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		k;
	char	**outp;
	int		len;

	if (!s)
		return (NULL);
	len = get_n_words(s, c);
	outp = (char **)malloc(sizeof(char *) * (len + 1));
	if (!outp)
		return (NULL);
	k = 0;
	while (k < (len + 1))
	{
		outp[k] = NULL;
		k++;
	}
	if (run_string(s, c, outp) == -1)
		return (NULL);
	return (outp);
}

/*int	main()
{
char 	**test;

	test = ft_split("hola mon", ' ');
	printf("string:%s\n", test[0]);
	// printf("%d", get_n_words("ho la m o n", ' '));



	return (0);
}*/
