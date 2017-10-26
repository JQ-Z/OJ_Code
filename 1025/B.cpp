#include <stdio.h>
#include <math.h>
 
int main()
{
    int blank;
    while((scanf("%d", &blank) == 1))
    {
        int index = 0,finish = 0;
        if(blank % 2 == 0 || blank == 1){
            printf("2^? mod %d = 1\n", blank);
        } else {
            while(index < blank)
            {
                 
                if((long long)pow(2,++index) % blank == 1){
                    printf("2^%d mod %d = 1\n",index,blank);
                    finish++;
                    break;
                }
            }
            if(finish == 0)printf("2^%d mod %d = 1\n",index - 1,blank);
        }
    }
    return 0;
}