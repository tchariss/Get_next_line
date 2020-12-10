#include <stdio.h>
# include <unistd.h>	// отступы после if, ifdef, ifndef + read
# include <stdlib.h> // malloc 
# include <string.h> 

size_t	strlen(const char *s) //** возвращает длину строки
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
size_t	ft_strlcpy(char * dst, const char * src, size_t dstsize)
{
	size_t a;
	size_t len;

	a = 0;
	if (src == NULL)
		return (0);
	len = strlen(src);
	if (dstsize > 0)
	{
		while (a < dstsize - 1 && src[a] != '\0' )
		{
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	return(len);
}

char *mini_keep_bufs(char *str) {
	static char *backup;
	char *new_backup;
	// new_backup의 길이를 구하기
	size_t len = strlen(backup) + strlen(str);

	if (!(new_backup = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);

	// new_backup에 backup 값과 새로운 값 복사
	size_t idx = ft_strlcpy(new_backup, backup, len + 1);
	ft_strlcpy(new_backup + idx, str, len + 1);	

	// backup이 new_backup을 가리키도록 설정
	free(backup);
	backup = new_backup;
	return (backup);
}

int main(void) {
	printf("%s\n", mini_keep_bufs("Hello 42"));
	printf("%s\n", mini_keep_bufs(" world, "));
	printf("%s\n", mini_keep_bufs("yekim!"));
	return (0);
}
// 실행 결과
// Hello 42
// Hello 42 world, 
// Hello 42 world, yekim!