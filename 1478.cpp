#include <stdio.h>
#include <string.h>
#include <math.h>

bool arr[15000][15000];
int x = 1, y = 1;
int main()
{
	int n, a;
	scanf("%d", &n);
	for(a = 0; pow(2,a) < (n*1.0);a++);

	arr[x][y] = 1;

	for(int i = 1; i <= a; i++)
	{
		x *= 2;
		y *= 2;
		for(int i_x = x / 2 + 1; i_x <= x; i_x++)
		{
			for(int i_y = 1 ; i_y <= y / 2; i_y++)
			{
				arr[i_x][i_y] = arr[i_x - (x/2)][i_y];
			}
		}
		for(int i_x = 1; i_x <= x / 2; i_x++)
		{
			for(int i_y = y / 2 + 1; i_y <= y; i_y++)
			{
				arr[i_x][i_y] = arr[i_x][i_y - (y / 2)];
			}
		}
		for(int i_x = x / 2 + 1; i_x <= x; i_x++)
		{
			for(int i_y = y / 2 + 1; i_y <= y; i_y++)
			{

				arr[i_x][i_y] = arr[i_x - (x/2)][i_y - (y/2)] == 0?1:0;
			}
		}
	}

	for(int i = 1; i <= x; i++)
	{
		for(int m = 1; m <= y; m++)
		{
			printf("%d", arr[i][m]);
		}
		printf("\n");
	}

	return 0;
}