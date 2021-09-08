#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 4000

typedef struct num{
    int value;
    struct num *next;
} num;

num *hash_table[TABLE_SIZE];

void init_hash_table(){
    for (int i = 0; i < TABLE_SIZE;i++){
        hash_table[i] = NULL;
    }
}

int hash(int value){
    value = (value > 0) ? value : -value;
    return (value % TABLE_SIZE);
}

void insert_hash_table(int value){
    int hash_index = hash(value);
    num *newnode = malloc(sizeof(num));
    newnode->value = value;
    newnode->next = hash_table[hash_index];
    hash_table[hash_index] = newnode;
}

bool hash_table_search(int value){
    int hash_index = hash(value);
    num *temp = hash_table[hash_index];
    while(temp!=NULL){
        if(hash_table[hash_index]->value==value)
            return true;
        temp = temp->next;
    }
    return false;
}

bool containsDuplicate(int* nums, int numsSize){
    init_hash_table();
    for (int i = 0; i < numsSize;i++){
        if(!hash_table_search(nums[i]))
            insert_hash_table(nums[i]);
        else if(hash_table_search(nums[i]))
            return true;
    }
    return false;
}

void print_hash_table(){
    for (int i = 0; i < TABLE_SIZE;i++){
        if(hash_table[i]!=NULL){
            printf("hash index = %d, value = %d\n", i, hash_table[i]->value);
        }
    }
}

int main(){
    int nums[] = {1,1,1,3,3,4,3,2,4,2};
    int result = containsDuplicate(nums, sizeof(nums) / sizeof(int));
    if(result==0)
        printf("false\n");
    else if(result==1)
        printf("true\n");
    print_hash_table();
    return 0;
}