/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:31:45 by tchariss          #+#    #+#             */
/*   Updated: 2020/12/17 15:39:37 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Возвращает длину строки
size_t	strlen(const char *s)
{
	size_t	a;
	
	a = 0;
	if (s == NULL)
		return (0); 
	while (s[a] != '\0')
	{
		a++;
	}
	return(a);
}

// Дублирует строку, на кот указывает S
// Память под дубликат строки выделяется с помощью malloc
char	*strdup(const char *s)
{
	char	*new_s;
	int		a;
	int		b;
	
	a = 0;
	b = 0;
	new_s = malloc(sizeof(char) * (strlen(s) + 1));
	if (new_s == NULL)
		return (NULL);
	while(s[a] != '\0')
	{
		new_s[b] = s[a];
		a++;
		b++;
	}
	new_s[b] = '\0';
	return(new_s);
}

// Функция ft_strjoin выделяет (с помощью malloc) и возвращает «свежую» строку, заканчивающуюся на \0, 
// в результате объединения s1 и s2. Если распределение завершается неудачно, функция возвращает NULL
char	*strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		a;
	int 	b;
	
	a = 0;
	b = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = malloc(sizeof(char) *((strlen(s1) + strlen(s2)) + 1)); // str (+1) - с последним знаком '\0' 
	if (new_str == NULL)
		return (NULL);
	while (s1[a] != '\0')
	{
		new_str[a] = s1[a];
		a++;
	}
	while (s2[b] != '\0')
	{
		new_str[a++] = s2[b++];
	}
	new_str[a] = '\0';
	return (new_str);
}

// Поиск в строке , первое вхождение символа
// s – указатель на строку, где осуществляться поиск, с – код искомого символа
char	*strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c && c != '\0')
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*strcopy(char *s1, const char *s2)
{
	while (*s2 != '\0')
	{
		*s1++ = *s2++;	
	}
	*s1 = '\0';
	return (s1);
}

void	strclear(char *s)
{
	while(*s != '\0')
	{
		*s = '\0';
		s++;	
	}
}