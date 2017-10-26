#include <stdio.h>
 
int arr[100005] = {0};
 
int main()
{
    arr[1] = 1;
    for(int i = 2; i <= 100000;i++)arr[i] = arr[i-1]+2;
    int n;
    scanf("%d", &n);
    while(n > 0)
    {
        int blank;
        scanf("%d", &blank);
        int sum = 0;
        for(int t = 1; t <= blank;t++)
        {
            sum +=arr[t];
            sum %= 10000;
        }
        printf("%d\n", sum);
        n--;
    }
    return 0;
}