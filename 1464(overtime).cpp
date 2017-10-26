#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[1005][100];
char ex = '\0';
int map_index = 0;
int map[1005] = {0};
bool mark[1005] = {0};
int t;

int find(int length)
{
	if(length == t){
		for(int w = 0; w <= map_index;w++)printf(w != map_index?"%s.":"%s\n",arr[map[w]]);
		return 1;
	}	

	if(ex == '\0'){
		for(int i = 0; i < t; i++)
		{
			mark[i] = 1;
			ex = arr[i][strlen(arr[i])-1];
			map[map_index++] = i;
			if(find(length+1))return 1;
			mark[i] = 0;
			map[--map_index] = 0;
		}	
	} else {
		for(int i = 0; i < t; i++)
		{
			if(mark[i] != 1 && ex == arr[i][0]){
				char blank = ex;
				mark[i] = 1;
				ex = arr[i][strlen(arr[i])-1];
				map[map_index++] = i;
				if(find(length+1))return 1;				
				mark[i] = 0;
				map[--map_index] = 0;
				ex = blank;
			}
		}
	}
	return 0;

}

int main()
{
	int T;
	scanf("%d\n", &T);
	for(int i = 1; i <= T; i++)
	{
		char ch[100];
		scanf("%d\n", &t);
		for(int index = 0; index < t; index++)
		{
			gets(ch);
			strcpy(arr[index], ch);
		}
		for(int q = 0; q < t; q++)
		{
			for(int w = q + 1; w < t; w++)
			{
				if(strcmp(arr[q],arr[w]) > 0){
					strcpy(ch,arr[q]);
					strcpy(arr[q],arr[w]);
					strcpy(arr[w],ch);
				}
			}
		}
		if(find(0) == 0)printf("***\n");
	}
	return 0;
}


