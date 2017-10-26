#include <stdio.h>
 
bool arr[1000002] = {0};
 
int main()
{
    int index = 1,mark = 1,finish = 0;
    while(mark <= 1000002)
    {
        arr[mark] = 1;
        for(int i = 1; i < mark; i++)
        {
            if(arr[i] == 1){
                if((mark + i) > 1000000){
                    finish++;
                    break;
                }
                arr[mark + i] = 1;
            }
        }
        mark *= ++index;
        if(finish == 1)break;
    }
    int blank;
    while((scanf("%d", &blank) == 1) && blank >= 0)
    {
        printf(arr[blank] == 1 ? "YES\n" : "NO\n");
    }
    return 0;
}