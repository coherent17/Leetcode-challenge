#include <stdio.h>
#include <stdbool.h>

bool isValid(char * s){
    char stack[10000];
    int count = 0;
    while(*s!='\0'){
        switch(*s){
            case '(':
                stack[count++] = ')';
                break;
            case '[':
                stack[count++] = ']';
                break;
            case '{':
                stack[count++] = '}';
                break;
            case ')': case ']': case'}':
                if(count==0||stack[--count]!=*s)
                    return false;
        }
        s++;
    }
    return (count == 0);
}

int main(){
    char s[] = "{[]}";
    printf("%d\n", isValid(s));
    return 0;
}