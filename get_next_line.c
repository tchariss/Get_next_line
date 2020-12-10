/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:32:09 by tchariss          #+#    #+#             */
/*   Updated: 2020/12/10 16:04:04 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> // open
#include <stdio.h> // printf

#include "get_next_line.h" // - включить созданную библиотеку 



// Ф-ия GNL записывает в *line считанную из fd строку до первого символа \n
int 	get_next_line(int fd, char **line)
//line - буква, *line - строка(линия), **line - адрес строки
{
	char		buf[BUFFER_SIZE + 1]; //создаем буфер на BUFF_SIZE количество символов
// Всем функциям со строками необходим '\0' - символ конца строки
// Нужно его установить // +1 -> '\0'
	int			count_sym_in_str; // 
	static char	*static_memory;
	char 		*ukaz_n;
	// int 		stop; ///?????????

	// stop = 1;
	
				// if (line == NULL)
				// 	return (-1);
	static_memory = 0;
	if (static_memory != NULL)
		*line = strdup(static_memory);
	else 
		*line = strdup(""); // Иницициализируем переменную, чтобы не было мусора 
	while((count_sym_in_str = read(fd, buf, BUFFER_SIZE)) != '\0') // чтения из файла 
// Read - возвращает количество действительно считанных байт	
	// Пока есть что читать -> продолжаем, если нет -> заканчиваем цикл
	{
		buf[count_sym_in_str] = '\0';
		if ((ukaz_n = strchr(buf, '\n')) != '\0')
		{
			*ukaz_n = '\0'; // Всё что до '\n' копируем в line
			// stop = 0;
			ukaz_n++;
			static_memory = strdup(ukaz_n);
		}
// (1) - файловый описатель(название) откуда все будет браться - (fd)
// (2) - аргумент(адрес) указывающий на файл - (buf)
// (3) - сколько количество байт нужно считывать из файла - (BUFFER_SIZE)
		*line = strjoin(*line, buf); // strjoin - Объединяет строки в "свежую" строку, заканчивающуюся на \0 
// ЕСЛИ strdup, то копируем прочитанное из buf в line || дублируем строку buf в line
// strdup - возвращает указатель на новую строку
	}
	return (0);
	// RETURN : 1 - строка прочитана и конец файла не достигнут -> в line записывается новая строка
	// 0 - line прочитана, строка записана и файл закончился (Чтение файла завершено)
	// -1 - любые ошибки (много памяти , fd испорчен , line == null и тд)
}

// int main()
// {
// 	char *line;
// 	int fd;
	
// 	fd = open("fox.txt", O_RDONLY); // fd(1,2) -> 1 - имя файла, 2 - (флаги) как его будем открывать :
// 	// O_RDONLY - только для чтения, O_WRONLY - только для записи, O_RDWR - для чтения и записи
// 	get_next_line(fd, &line);
// 	printf("%s\n", line);
// }

int main(void)
{
    int fd;
    char **line;
    int ret;

    fd = open("fox.txt", O_RDONLY);
    if (!(line = (char **)malloc(sizeof(char*) * 10000)))
        return (0);

    while ((ret = get_next_line(fd, line)) > 0)
    {
        printf("%s\n", *line);
        printf("%i\n", ret);
        free(*line);
    }
    printf("%s\n", *line);
    printf("%i\n", ret);
    free(line);
    return(0);
}
	
	// Ф-ия GNL записывает в *line считанную из fd строку до первого символа \n

// int 	get_next_line(int fd, char **line)
// {
// 	// char	*buf; // buf[BUFF_SIZE+1]
// 	// s
// 	// char	a;
// 	// size_t	count;
// 	// count = BUFF_SIZE;
	
// 	// buf = (char *)malloc(sizeof(char)* (count + 1));
// 	// a = read(fd, buf, count);
// 	if (line == NULL)
// 		return (-1);
	
// }

//static int startendline()
