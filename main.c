#include "ft_printf.h"

int main (void)
{
	int a;
	char *s;
	char b;
	
	a = -5;
	b = 'c';
	s = "yujgt";
	int u = -2;

	ft_printf("%c %d %s %u %% %p\n", b, a ,s, u, 42069);
	printf("%c %d %s %u %% %p\n", b, a ,s, u, 42069);


}