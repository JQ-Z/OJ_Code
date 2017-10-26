#include <stdio.h>
#include <string.h>
#include<algorithm>
#include <iostream>
#include <map>

using namespace std;


map<string, int> ch_mark;
int num;
char ch[30];
bool mark[30];
char ans[30];

void find(int start)
{
	if(start == num){
		printf("%s\n", ans);
		ans[start] = '\0';
		return;
	}
	for(int i = 0; i < num; i++)
	{
		if(mark[i] == 1)continue;
		ans[start] = ch[i];

		if(ch_mark.find(ans) != ch_mark.end()){
			ans[start] = '\0';
			continue;
		}
		ch_mark.insert(pair<string, int>(ans,0));
		mark[i] = 1;
		find(start + 1);
		ans[start] = '\0';
		mark[i] = 0;
	}
}

int main()
{
	scanf("%d\n", &num);
	scanf("%s", &ch);
	sort(ch, &(ch[num]));
	find(0);

	return 0;
}