#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 20
#define EMPTY -1

typedef struct number{
    int value;
} number;

number hash_table[TABLE_SIZE];

int next_number(int number){
    int result = 0;
    while(number>0){
        result += (number % 10)*(number % 10);
        number = number/10;
    }
    return result;
}

void init_hash_table(){
    for (int i = 0; i < TABLE_SIZE;i++){
        hash_table[i].value = EMPTY;
    }
}

int hash(int number){
    int temp = number % TABLE_SIZE;
    return temp;
}

bool insert_hash_table(int value){
    int hash_index = hash(value);
    for (int i = 0; i < TABLE_SIZE;i++){
        int try = (hash_index + i) % TABLE_SIZE;
        if(hash_table[try].value==EMPTY){
            hash_table[try].value = value;
            return true;
        }
        else if(hash_table[try].value==value)
            return false;
    }
    return false;
}

bool isHappy(int n){
    init_hash_table();
    while(insert_hash_table(n)){
        n = next_number(n);
        if(n==1)
            return true;
    }
    return false;
}

void print_hash_table(){
    for (int i = 0; i < TABLE_SIZE;i++){
        if(hash_table[i].value!=EMPTY){
            printf("%d ", hash_table[i].value);
        }
    }
    printf("\n");
}

int main(){
    printf("%d\n", isHappy(1999999999));
    print_hash_table();
    return 0;
}