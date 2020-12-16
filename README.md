# Get_next_line
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:32:09 by tchariss          #+#    #+#             */
/*   Updated: 2020/12/16 19:10:21 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> 
#include <stdio.h> 
#include "get_next_line.h" 

char	*proverka_static_memory(char *static_memory, char **line)
{
	char	*next_line;// указ на новую линию

	next_line = NULL;
	if (static_memory != NULL)
	{
		if ((next_line = strchr(static_memory, '\n'))) // если static_memory не пустой
		{
			*next_line = '\0';
			*line = strdup(static_memory);
			next_line++;
			strcopy(static_memory, next_line); // сдвиг (проспускаем \n)
		}
		else
		{
			*line = strdup(static_memory);
			strclear(static_memory);
		}
	}
	else
		*line = strdup("");
	return (next_line);
}

int 	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1]; 	
	int			count_sym_in_str; 	
	static char	*static_memory; // остаток, который после '\0'
	char 		*ukaz_n;
	//int			stop; // - для остановки цикла, как флаг, 1 - true, 0 - останавливает  цикл (false)
	char		*saveper; // временная переменная
	
	//stop = 1; // true
	ukaz_n = proverka_static_memory(static_memory, line);
	// if (static_memory != NULL)
	// 	*line = strdup(static_memory);
	// else 
	// 	*line = strdup(""); 	
	while (ukaz_n == 0 && (count_sym_in_str = read(fd, buf, BUFFER_SIZE)) > 0) 		
	{
		buf[count_sym_in_str] = '\0';
		if ((ukaz_n = strchr(buf, '\n')) != NULL)
		{
			*ukaz_n = '\0'; 						
		//	stop = 0; // остановка цикла
			ukaz_n++;
			static_memory = strdup(ukaz_n);
		}
		saveper = *line; // сохраним старое значение line
		*line = strjoin(*line, buf);
		free(saveper);
	}
	// if ((count_sym_in_str != 0) || (static_memory) != 0) || (strlen(*line) != 0))
	if (strlen(static_memory) || ukaz_n)
		return (1);
	return (0);
}

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
		printf("|%i| %s\n", ret, *line);
        free(*line);
    }
    printf("|%i| %s\n", ret, *line);
    free(line);
    return(0);
}
// int main()
// {
// 	char *line;
// 	int fd;
	
// 	fd = open("fox.txt", O_RDONLY); // fd(1,2) -> 1 - имя файла, 2 - (флаги) как его будем открывать :
// 	// O_RDONLY - только для чтения, O_WRONLY - только для записи, O_RDWR - для чтения и записи
// 	get_next_line(fd, &line);
// 	printf("%s\n", line);
// 	get_next_line(fd, &line); // 3 строка
// 	printf("%s\n", line);
// 	get_next_line(fd, &line); // 4 строка
// 	printf("%s\n", line);
// }
	
	
	

