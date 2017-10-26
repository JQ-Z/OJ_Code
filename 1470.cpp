#include <stdio.h>
 
 
int main()
{
    int n, k;
    int map[101][2] = {0};
    int count = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < k; i++)
    {
        int a,b;
        scanf("%d %d",&a, &b);
        if(map[a][0] > 0){
            map[b][0] = map[a][0];
            if(map[b][1] == 1){
                map[b][1] = 0;
            }
        } else {
            if(map[b][0] > 0){
                if(map[b][1] == 1){
                    map[b][1] = 0;
                    map[a][0] = map[b][0];
                    map[a][1] = 1;
                } else {
                    map[a][0] = map[b][0];
                }
            } else {
                map[a][0] = ++count;
                map[a][1] = 1;
                map[b][0] = count;
            }
        }
 
    }
    int result[101] = {0};
    int in = 0;
    for(int i = 1; i <= n;i++)
    {
        if(map[i][0] > 0){
            if(map[i][1] == 1){
                result[in++] = i;
            }
        } else {
            result[in++] = i;
        }
    }
    printf("%d\n", in);
    for(int q = 0; q < in;q++)
    {
        printf(q==0?"%d":" %d", result[q]);
    }
 
    return 0;
}