#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

　
typedef unsigned int uint;

　
void Mergesort(int *c, int first, int last, int length)
{
	if (last - first == 0)
		return;
	int k = (last+first) / 2;
	Mergesort(c, first, k, length);
	Mergesort(c, k + 1, last, length);
	int *mass = (int*)malloc((length)*sizeof(int));
	for (int i = first; i < last + 1; i++)
		mass[i] = c[i];
 	int a = first, b = k + 1;
	for (int i = first; i < last + 1; i++)
		if (a <= k && b <= last)
		{
			if (mass[a] < mass[b])
			{
				c[i] = mass[a];
				a++;
			}
			else
			{
				c[i] = mass[b];
				b++;
			}
		}
		else
			if (b > last)
			{
				c[i] = mass[a];
				a++;
			}
			else
			{
				c[i] = mass[b];
				b++;
			}
	free(mass);
}

　
int main(void)
{
	int length = 8;
	int *m1 = (int*)malloc((length)*sizeof(int));
	m1[0] = 7;
	m1[1] = 5;
	m1[2] = 4;
	m1[3] = 1;
	m1[4] = 2;
	m1[5] = 8;
	m1[6] = 6;
	m1[7] = 3;	
	Mergesort(m1, 0, length - 1, length);
	for (int i = 0; i < length; i++)
		printf("%i\n", m1[i]);
	return 0;
}
