#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
    char character;
    struct node *next;
} node;

typedef struct{
    node *head;
} stack;

void init_stack(stack *s){
    s->head = NULL;
}

bool push(stack *s, char charcacter){
    node *newnode = malloc(sizeof(node));
    newnode->character = charcacter;
    newnode->next = s->head;
    s->head = newnode;
    return true;
}

char pop(stack *s){
    char result = s->head->character;
    node *temp = s->head;
    s->head = s->head->next;
    free(temp);
    return result;
}

bool isValid(char * s){
    //stack acclaim
    stack mystack;
    init_stack(&mystack);
    int stringLength = strlen(s);
    for (int i = 0; i < stringLength;i++){
        if(s[i]=='('){
            push(&mystack, ')');
        }
        else if(s[i]=='['){
            push(&mystack, ']');
        }
        else if(s[i]=='{'){
            push(&mystack, '}');
        }
        else if(mystack.head==NULL || s[i]!=pop(&mystack)){
            return false;
        }
    }
    return (mystack.head == NULL);
}

int main(){
    char s[] = "{[]}";
    printf("%d\n", isValid(s));
    return 0;
}