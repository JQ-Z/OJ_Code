#include <stdio.h>
#include <math.h>
int check(int a, int b, int c){
    return b * b >= 4 * a * c ? 1 : 0;
}
 
int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(check(a, b, c)){
        double zs = 0.0 - b + sqrt((b * b) - (4 * a * c));
        double fs = 0.0 - b - sqrt((b * b) - (4 * a * c));
        zs = zs / (2 * a);
        fs = fs / (2 * a);
        printf("%.2f %.2f\n", zs, fs);
    }
    return 0;
}