#include <stdio.h>
int map[101][101] = {0};
int main(){
	int n, x, y;
	char blank;
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%c", &blank);
			if(blank == '-'){
				map[i][j] = -1;
			} else if(blank == '+'){
				map[i][j] = 1;
			} else if(blank == 'A'){
				map[i][j] = 0;
				x = i;
				y = j;
			} else {
				map[i][j] = 99; 
			}
			getchar();
		}
	}
	int head, end, finish = 0;
	int count[10005][4];
	head = end = 0;
	count[end][0] = x;
	count[end][1] = y;
	count[end][2] = map[x][y];
	count[end++][3] = 0;
	while(head <= end)
	{
		x = count[head][0];
		y = count[head][1];
		if(map[x][y] == 99){
			finish = 1;
			break;
		}
		map[x][y] = 50;
		if(x + 1 < n && map[x + 1][y] != 50 && count[head][2] != map[x + 1][y] ){
				count[end][0] = x + 1;
				count[end][1] = y;
				count[end][2] = map[x + 1][y];
				count[end++][3] = count[head][3] + 1;
		}
		if(x - 1 >= 0 && map[x - 1][y] != 50 && count[head][2] != map[x - 1][y] ){
				count[end][0] = x - 1;
				count[end][1] = y;
				count[end][2] = map[x - 1][y];
				count[end++][3] = count[head][3] + 1;
		}
		if(y + 1 < n && map[x][y + 1] != 50 && count[head][2] != map[x][y + 1] ){
				count[end][0] = x;
				count[end][1] = y + 1;
				count[end][2] = map[x][y + 1];
				count[end++][3] = count[head][3] + 1;
		}
		if(y - 1 >= 0 && map[x][y - 1] != 50 && count[head][2] != map[x][y - 1] ){
				count[end][0] = x;
				count[end][1] = y - 1;
				count[end][2] = map[x][y - 1];
				count[end++][3] = count[head][3] + 1;
		}
		head++;
	}
	if(finish == 1){
		printf("%d\n", count[head][3]);
	} else {
		printf("Error\n");
	}
	return 0;
}