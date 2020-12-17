/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:14:26 by tchariss          #+#    #+#             */
/*   Updated: 2020/12/16 17:04:21 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H	 // проверяем было ли уже включено GNL (Нет, не было -> значить включить) то есть повторные включения буду исключены
# define GET_NEXT_LINE_H	// присвоить имя // имена макросов имеют только заглавные буквы

// # define BUFFER_SIZE 1 // gcc ... -D BUFFER_SIZE=2000

# include <unistd.h>	// отступы после if, ifdef, ifndef + read
# include <stdlib.h> // malloc 
# include <string.h> 

int		get_next_line(int fd, char **line); // Ф-ия GNL записывает в *line считанную из fd строку до первого символа \n
char	*strdup(const char *s); // Дублирует строку, на кот указывает S
size_t	strlen(const char *s); // Возвращает длину строки
char	*strjoin(char const *s1, char const *s2); // Объединяет строки в "свежую" строку, заканчивающуюся на \0,
char	*ft_strchr(const char *s, int c);// Ищет первое вхождения символа(с) в *s
char	*strcopy(char *s1, const char *s2);
void	strclear(char *s);

#endif
