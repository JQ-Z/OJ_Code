#include <stdio.h>
#include <math.h>

long long arr[93000] = {0};

int main()
{
	arr[1] = 1;
	arr[2] = 2;
	int index = 2;
	for(int i = 3;i <= 92685;i++)
	{
		if(i % 2 == 1)arr[i] = arr[i-1] + index;
		if(i % 2 == 0)arr[i] = arr[i-1] + index++;
	}
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++)
	{
		int a, b, c;
		scanf("%d%d", &a, &b);
		c = b - a;
		int q = 1;
		while(c > arr[q])q++;
		printf("%d\n", q);
	}
	return 0;
}