/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:02:24 by tchariss          #+#    #+#             */
/*   Updated: 2020/11/30 13:03:06 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	trystat()
{
	int fade = 1;
	static int stay = 1;

	printf("fade = %d и stay = %d\n", fade++, stay++);
	return (0);
}

int main()
{
	int count;
	count = 1;
	while (count <= 4)
	{	
		printf( "Итерация %d : ", count);
		trystat();
		count++;
	}
}

// void foo()
// {
//     int a = 10;
//     static int sa = 10;

//     a += 5;
//     sa += 5;

//     printf("a = %d, sa = %d\n", a, sa);
// }


// int main()
// {
//     int i;

//     for (i = 0; i < 10; ++i)
//         foo();
// }

// #include <stdio.h>

// void f(void)
// {
// 	static int n = 0;
// 	int a = 0;
// 	printf("%s%d%s", "n = ",n ,", ");
// 	printf("%s%d\n", "a = ",a );
// 	n++;
// 	a++;
// }

// int main (void)
// {
// 	f();
// 	f();
// 	f();
// }