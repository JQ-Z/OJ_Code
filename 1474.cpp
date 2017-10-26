#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int n,sum = 0;
    scanf("%d", &n);
 
    for(int i = 0; i < n; i++)
    {
        int blank;
        scanf("%d", &blank);
        if(blank == (sum + 1)){
            sum = blank;
        }
    }
    printf("%d",n - sum);
    return 0;
     
}