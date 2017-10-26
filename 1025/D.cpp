#include <stdio.h>
 
int arr[100003] = {0};
 
int main()
{
    int i = 1, index_x = 3,index_m = 5;
    while(i <= 100001)
    {
        if(index_x < index_m){
            arr[i++] = index_x;
            index_x +=3;
        } else {
            arr[i++] = index_m;
            if(index_x == index_m){
                index_x += 3;
            }
            index_m += 5;
        }
    }
 
    int blank;
 
    while((scanf("%d", &blank) == 1))
    {
        printf("%d\n", arr[blank]);
    }
    return 0;
}