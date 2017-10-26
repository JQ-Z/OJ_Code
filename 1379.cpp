#include <stdio.h>
 
void check(int num, int start){
    for(int i = start; i <= num; i++){
        if(num % i == 0){
            if(num == i){
                printf("%d\n", i);
                break;
            } else {
                printf("%d*", i);
                num /= i;
                check(num, i);
                break;
            }
        }
    }
}
 
int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    for(int i = x; i <= y; i++)
    {
        printf("%d=", i);
        check(i,2);
    }
   