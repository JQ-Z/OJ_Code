#include <stdio.h>
 
int main()
{
    int n;
    scanf("%d", &n);
    int pre, max,first = 1;
    for(int i = 1; i <= n; i++)
    {
        int value;
        scanf("%d", &value);
        if(first = 1){
            first = 0;
            pre = value;
            max = value;
        } else {
            if(pre < 0){
                pre = value;
                max = value > max ? value : max;
            } else {
                pre += value;
                max = pre > max ? pre : max;
            }
        }
    }
    printf("%d\n", max);
    return 0;   
}