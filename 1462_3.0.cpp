#include <stdio.h>


int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T;t++)
	{
		int blank;
		scanf("%d", &blank);
		int a, b, c, result = 999999;
		for(a = blank; a >= 1; a--){
			for(b = a; b >= 1; b--){
				if(a * b > blank || blank % (a * b) != 0)continue;
				c = blank / (a * b);
				int S = a * b * 2 + a * c * 2 + b * c * 2;
				result = result < S ? result : S;
			}
		}
		printf("%d\n", result);
	}
}