#include <iostream>
#include <malloc.h>

using namespace std;

int a, b, c;
int *arr;

void check()
{
	int sum = 0;
	for(int i = 0; i < b;i++)
		{
			sum+=arr[i];
		}
	if(sum == c)
		{
			for(int i = b - 1 ; i >= 0;i--)
				{
					cout << arr[i]<<" ";
				}
				cout<<"\n";
		}
}

void select(int start, int count)
{
	if(start >  a) return;
	//cout<<start;
	select(start + 1, count);

	arr[--count] = start;

	if(count == 0){
		check();
	} else {
		select(start + 1, count);
	}
}

int main()
{

	cin>>a>>b>>c;
	arr = (int *)malloc(sizeof(int) * (b+1));
	select(1 ,b);
	return 0;
}
