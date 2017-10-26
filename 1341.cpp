#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
 
using namespace std;
 
char status[1000000][10];
int count[1000000][2];
map<string ,int> check;
 
int main()
{
    int head, iend;
    head = iend = 0;
    char ch[10];
    char jg[10];
    gets(ch);
    gets(jg);
//  printf("%s\n%s\n", ch, jg);
//  return 0;
    //char ch[10] = "3 7642581";
    //char ch[10] = "12475 638";
//  char jg[10] = "12345678 ";
    strcpy(status[head], ch);
    count[head][0] = 0;
    count[head][1] = 0;
    check.insert(pair<string ,int>(status[head], 0));
    while(head <= iend)
    {
         
        if(strcmp(status[head], jg) == 0){
            break;
        }
        int blank;
        for(int i = 0; i < 9; i++)
        {
            if(status[head][i] == '.'){
                blank = i;
                break;
            }
        }
        if(blank - 3 >= 0){ //UP
            char ch[10];
            strcpy(ch, status[head]);
            ch[blank] = ch[blank - 3];
            ch[blank - 3] = '.';
            if(check.find(ch) == check.end()){
                strcpy(status[++iend], ch);
                count[iend][0] = count[head][0] + 1;
                count[iend][1] = head;
                check.insert(pair<string ,int>(ch, 0));
            }
        }
         
        if((blank+1) % 3 != 1 ){ //L
            char ch[10];
            strcpy(ch, status[head]);
            ch[blank] = ch[blank - 1];
            ch[blank - 1] = '.';
     
            if(check.find(ch) == check.end()){
                strcpy(status[++iend], ch);
                count[iend][0] = count[head][0] + 1;
                count[iend][1] = head;
                check.insert(pair<string ,int>(ch, 0));
            }
        }
         
        if(blank + 3 < 9){ //DOWN
            char ch[10];
            strcpy(ch, status[head]);
            ch[blank] = ch[blank + 3];
            ch[blank + 3] = '.';
            if(check.find(ch) == check.end()){
                strcpy(status[++iend], ch);
                count[iend][0] = count[head][0] + 1;
                count[iend][1] = head;
                check.insert(pair<string ,int>(ch, 0));
            }
        }
         
        if((blank+1) % 3 != 0 ){ //R
            char ch[10];
            strcpy(ch, status[head]);
            ch[blank] = ch[blank + 1];
            ch[blank + 1] = '.';
            if(check.find(ch) == check.end()){
                strcpy(status[++iend], ch);
                count[iend][0] = count[head][0] + 1;
                count[iend][1] = head;
                check.insert(pair<string ,int>(ch, 0));
            }
        }
        head++;
         
    }
        printf("%d\n", count[head][0]);
    return 0;
     
}