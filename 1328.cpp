#include <stdio.h>
 
int main()
{
 
        int h;
        scanf("%d", &h);
        int arr[h][h];
        for(int w = 0;w < h; w++){
            for(int q = 0; q <= w;q++)scanf("%d", &arr[w][q]);
        }
        for(int w = h - 2;w >= 0; w--){
            for(int q = 0; q <= w;q++)arr[w][q] += arr[w+1][q]>arr[w+1][q+1] ? arr[w+1][q]:arr[w+1][q+1];         
        }
        printf("%d\n", arr[0][0]);
 
    return 0;
}