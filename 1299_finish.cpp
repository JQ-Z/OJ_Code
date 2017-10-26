#include <stdio.h>
 
int recursion(int num,int year){
    if(year == 1){
        return num * 2 - 1;
    } else {
        num = num * 2 - 1 ;
        return recursion(num, year-1) + num;
    }
}
 
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    for(int i = 1;;i++)
    {   
        if(b == (recursion(i,a) + i)){
            printf("%d\n", i); 
            break;
        }
    }
    return 0;
 
}