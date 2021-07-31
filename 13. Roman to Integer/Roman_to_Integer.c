#include <stdio.h>
#include <string.h>

int romanToInt(char *);

int main(){
    char s[]={"MCMXCIV"};
    printf("%d",romanToInt(s));
    return 0;
}


int romanToInt(char * s){
    //construct the table:
    int table[]={
        ['I'] = 1,
        ['V'] = 5,
        ['X'] = 10,
        ['L'] = 50,
        ['C'] = 100,
        ['D'] = 500,
        ['M'] = 1000
    };

    int sum=0;
    char next_element;
    while(*s!='\0'){
        next_element=*(s+1);
        //subtraction condition:(if it satisfied the condition, then skip the next letter)
        if(*s=='I'&&next_element=='V') sum+=4,s+=1;
        else if(*s=='I'&&next_element=='X') sum+=9,s+=1;
        else if(*s=='X'&&next_element=='L') sum+=40,s+=1;
        else if(*s=='X'&&next_element=='C') sum+=90,s+=1;
        else if(*s=='C'&&next_element=='D') sum+=400,s+=1;
        else if(*s=='C'&&next_element=='M') sum+=900,s+=1;
        else sum+=table[*s];
        //move to the next letter
        s+=1; 
    }
    return sum;
}