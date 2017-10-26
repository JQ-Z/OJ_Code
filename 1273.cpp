#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define STACK_SIZE 100
#define STACK_ADD 10
 
typedef struct sqstack{
    int *top;
    int *bottom;
    int max;
}sqstack;
 
void Initsatck(sqstack &s)
{
    s.bottom = (int *) malloc(STACK_SIZE * sizeof(int));
    s.top = s.bottom;
    s.max = STACK_SIZE;
}
 
int stackempty(sqstack &s){
    if(s.top == s.bottom)return 1;
    return 0;
}
 
int push(sqstack &s, int e)
{
    if(s.top - s.bottom >= s.max){
        s.bottom = (int *) realloc(s.bottom, (s.max+STACK_ADD)*sizeof(int));
        s.top = s.bottom + s.max;
        s.max += STACK_ADD; 
    }
    *s.top++ = e;
    return 1;
}
 
int pop(sqstack &s, int *e)
{   
    if(s.top == s.bottom)return 0;
    *e = *--s.top;
    return 1;
}
 
int main(){
    char ch[500];
    scanf("%s", ch);
    //int t = -1;
    while(ch[0] != '0'){
    //  t++;
        sqstack* s;
        s = (sqstack * )malloc(sizeof(int));
        Initsatck(*s);
        int c,ok = 1,length = strlen(ch);
        for(int i = 0; i < length; i++)
        {
            switch(ch[i])
            {
                case '(':{
                    push(*s,'(');
                    break;
                }
                case '[':{
                    push(*s,'[');
                    break;
                }
                case '{':{
                    push(*s,'{');
                    break;
                }
                case ')':{
                    pop(*s,&c);
                    if(c != '('){
                        ok = 0;
                    }
                    break;
                }
                case '}':{
                    pop(*s,&c);
                    if(c != '{'){
                        ok = 0;
                    }
                    break;
                }
                case ']':{
                    pop(*s,&c);
                    if(c != '['){
                        ok = 0;
                    }
                    break;
                }
            }
        }
        if(ok&&stackempty(*s)){
            printf("true\n");
        } else {
            printf("false\n");
        }
        scanf("%s", ch);
    }
    return 0;
}