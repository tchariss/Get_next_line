#include <unistd.h>
#include <stdlib.h> 
#include <stdio.h>
#include <fcntl.h> // open
#include "strdup.c"
#include "strjoin.c"
#include "strchr.c"
#include "strnew.c"
#include "strcpy.c"
#include "strclear.c"

// #include <fcntl.h> // open
// #include <stdio.h> // printf

// #include "get_next_line.h" // - включить созданную библиотеку 

char 	*check_rem(char *remember, char **line)
{
	char	*new_line; // переменная, куда сохраним указатель на новую линию

	new_line = NULL;
	if (remember != NULL) // если remember не пустой // будем копировать ( в зависимости от того есть ли новая линия или нет )
		if ((new_line = strchr(remember, '\n'))) // if strchr - если найдем в remember новую линию, то
		{
			*new_line = '\0'; // останавливаем копирование, то есть всё до '\0'(конца строки)
			*line = strdup(remember); // скопируем все что "до" в line
			new_line++;
			strcopy(remember, new_line); // копируем из new_line в remember 
		} // -> нашли, прочитали и записали строку
		else // если не встретили новую линию, то копируем все, что было
		{ 
			*line = strdup(remember);	// strdup - возвращает указатель на новую строку
			strclear(remember); // очистка всего, что там было
		}
	else // если в remember ничего нет 
		*line = strdup(""); // Иницициализируем переменную, чтобы не было мусора // создаем line новую локацию памяти 
	return (new_line); // Возвращаем указатель new_line // Если new_line нулевой, то нам нужно что-то читать// Если не нулевой , то читать ничего не нужно (в g_n_l -> read ..)
}

// Ф-ия GNL записывает в *line считанную из fd строку до первого символа \n
int	get_next_line(int fd, char **line) // line - буква, *line - строка(линия), **line - адрес строки
/*
	// RETURN : 1 - строка прочитана и конец файла не достигнут -> в line записывается новая строка
	// 0 - line прочитана, строка записана и файл закончился (Чтение файла завершено)
	// -1 - любые ошибки (много памяти , fd испорчен , line == null и тд
*/
{	// Создадим буффер на какое-то количество символов ( место для временного хранения данных )
	char		buf[10 + 1]; // сюда записываются 10 символ после read
	int			readbyte; // переменная, в которую записываю количество символов в строке(после read)
	char		*point_n; // указатель на '\n'
	int			stop; // - для остановки цикла 
	static char	*remember; // запомнить остаток, который после '\0 '
	char		*timevar; //временная переменная

	stop = 1;
	point_n = check_rem(remember, line); // может вернуть 0, тогда нужно читать, если нет то не нужно читат
	while (point_n == 0 && stop != 0 && (readbyte = read(fd, buf, 10))) //все ф-ям со строками необходим конец строки '\0' // и пока stop != null
	{ 
		buf[readbyte] = '\0';
		if ((point_n = strchr(buf, '\n')))
		{
			*point_n = '\0';// \n -> в \0//до '\n' нужно все скопировать в line
			stop = 0; // портим условие , stop остановит цикл и строка прочитается до конца // break; // принудительное окончание цикла
			point_n++; // сдвинуть указатель на 1 ячейку вперед, чтобы пропустить '\0'
			remember = strdup(point_n); // Скопируем строку из point_n в remember // Запишется все, что после '\0'
		}// *line = strdup(buf);// cкопируем символы из buf в line в переменную
		timevar = *line; // сохраним старое значение line
		*line = strjoin(*line, buf); //копируем прочитанное из buf в line || дублируем строку buf в lin// Запишется : всё, что до '\0'
		free(timevar); //очищение старого зачения *line
		// когда копируем последнюю часть из остатка и очищаем -> было что читать 
	}
	if ((readbyte != 0) || (strlen(remember) != 0) || (strlen(*line) != 0))
		return (1); // если что-то было прочитано
	return (0); // если файл закончился
	// Если readbyte не равно 0, значит что-то было прочитано или
	// Длина remember не равно 0, значит есть что читать 
	// Если длина *line не равно 0, значит что-то было записано и мы возвращаем не 0
		// (Чтобы последняя строка считалась и записалась)