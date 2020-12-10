/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:06:36 by tchariss          #+#    #+#             */
/*   Updated: 2020/12/07 12:42:31 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string.h>

char	*strjoin(char const *s1, char const *s2)
/*
Функция ft_strjoin выделяет (с помощью malloc) и возвращает «свежую» строку, заканчивающуюся на \0, 
в результате объединения s1 и s2. Если распределение завершается неудачно, функция возвращает NULL
*/ 

// объединяет строки в строку, разделенную пробелом {'a', 'bc', 'def'}
{
	char *str;
	size_t len;
	int a;
	int b;

	a = 0;
	b = 0;
	if (s1 == NULL || s2 == NULL)
		return(NULL);
	len = strlen(s1) + strlen(s2); 
	if (!(str = malloc(sizeof(char) * (len + 1)))) // выделяем память для str (+1) - с последним знаком '\0' 
		return (NULL); // ( if str == 0 -> return 0) /Users/tchariss/Desktop/vsc/libft/ft_strjoin.c
	while (s1[a] != '\0')
	{
		str[a] = s1[a];
		a++;
	}
	while (s2[b] != '\0')
	{
		str[a] = s2[b];
		b++;
		a++;
	}
	str[a] = '\0';
	return(str);
}
