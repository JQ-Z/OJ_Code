#include <stdio.h>
 
 
int sum = 0;
int n, m;
int map[101][101] = {0};
void dfs(int x, int y)
{
 
    map[x][y] = sum;
 
    if(x + 1 < n && map[x+1][y] > 0){
        dfs(x+1,y);
    }
    if(y + 1 < m && map[x][y+1] > 0){
        dfs(x,y+1);
    }
    if(x - 1 >= 0 && map[x-1][y] > 0){
        dfs(x-1,y);
    }
    if(y - 1 >= 0 && map[x][y-1] > 0){
        dfs(x,y-1);
    }
     
}
 
int main()
{
    scanf("%d%d", &n, &m);
    getchar();
    for(int i = 0; i < n; i++)
    {
        for(int y = 0; y < m; y++)
        {
            char z;
            scanf("%c", &z);
            map[i][y] = z - '0';
        }
        getchar();
    }
     
    for(int i = 0; i < n; i++)
    {
        for(int y = 0; y < m; y++)
        {
            if(map[i][y] <= 0){
                continue;
            } else {
                sum--;
                dfs(i,y);
                 
            }
        }
    }
     
    printf("%d", sum*(-1));
    return 0;
}