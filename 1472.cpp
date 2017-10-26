#include <stdio.h>
 
int main()
{
    int map[10005] = {0};
    map[0] = 1;
    for(int i = 1;i <= 10000; i++)
    {
        if(i >= 1){
            map[i] +=map[i - 1];
            map[i] %= 20170920;
        }
        if(i >= 4){
            map[i] +=map[i - 4];
            map[i] %= 20170920;
        }
        if(i >= 7){
            map[i] +=map[i - 7];
            map[i] %= 20170920;
        }
    }
     
    int blank;
    scanf("%d", &blank);
    while(blank != 0)
    {
        printf("%d\n", map[blank]);
        scanf("%d", &blank);
    }
    return 0;
}