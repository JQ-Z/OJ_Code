#include <stdio.h>
 
int main(){
    int T,time = 0;
    scanf("%d", &T);
    int result[T];
    while(time < T)
    {
        int n, m, blank, sum = 1;
        int Zcount = 0, Fcount = 0;
        scanf("%d%d", &n, &m); 
        int sz[n];
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &sz[i]);
            if(sz[i] > 0)Zcount++;
            if(sz[i] < 0)Fcount++;
        }
        for(int i = 0; i < n; i++)
            for(int w = i+1; w < n; w++)
                if(sz[i] > sz[w]){
                    blank = sz[i];
                    sz[i] = sz[w];
                    sz[w] = blank;
                }
 
        if(sz[0] >= 0){
            for(int i = 1; i <= m; i++)
            {
                sum *= sz[n-i];
            } 
        } else {
            int Fsmax = 1, Zsmax = 1;
            int Fsp = 0, Zsp = n-1;
            while(m > 0)
            {
                if(Fcount >= 2){
                    Fsmax = sz[Fsp] * sz[Fsp+1];
                    Zsmax = sz[Zsp] * sz[Zsp-1];
                }
                if(Fcount >= 2 && (Fsmax>=Zsmax || Zcount < m)){
                    Fcount -= 2;
                    m -= 2;
                    Fsp +=2;
                    sum *= Fsmax;
                } else {
                    sum *= sz[Zsp];
                    m--;
                    Zsp--;
                    Zcount--;
                }
            }
        }
        //printf("%d\n", sum);
        result[time] = sum;
        time++;
    }
    for(int i = 0; i < T; i++){
        printf("%d\n", result[i]);
    }
    return 0;
}