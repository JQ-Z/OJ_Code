#include<stdio.h>
 
int main ()
{
    int n,x;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    x= a[0];
    for(int i = 1;i < n;i++)
    {
        if(a[i] > x)
        {
            x=a[i];
        }
    }
    printf("%d",x);
    return 0;
} 