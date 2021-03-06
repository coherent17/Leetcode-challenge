#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 20000
#define EMPTY -1000000001

typedef struct{
    int value;
    int index;
} table;

table hash_table[TABLE_SIZE];

void init_hash_table(){
    for (int i = 0; i < TABLE_SIZE;i++){
        hash_table[i].value = EMPTY;
    }
}

int hash(int value){
    value = value > 0 ? value : -value;
    return (value*3) % TABLE_SIZE;
}

void insert_hash_table(int value, int index){
    int hash_index = hash(value);
    for (int i = 0; i < TABLE_SIZE;i++){
        int try = (hash_index + i) % TABLE_SIZE;
        if(hash_table[try].value==EMPTY){
            hash_table[try].value = value;
            hash_table[try].index = index;
            return;
        }
    }
}

int hash_table_search(int value){
    int hash_index = hash(value);
    for (int i = 0; i < TABLE_SIZE;i++){
        int try = (hash_index + i) % TABLE_SIZE;
        if(hash_table[try].value==EMPTY){
            return -1;
        }
        else if(hash_table[try].value==value){
            return hash_table[try].index;
        }
    }
    return -1;
}

//time complexity: O(n)
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    table hash_table[TABLE_SIZE];
    init_hash_table(hash_table);
    *returnSize = 2;
    int *result = malloc(sizeof(int) * (*returnSize));

    for (int i = 0; i < numsSize;i++){
        int compliment = target - nums[i];
        int index = hash_table_search(compliment);
        if(index!=-1){
            result[0] = i;
            result[1] = index;
            break;
        }
        else
            insert_hash_table(nums[i], i);
    }
    return result;
}

void print_hash_table(){
    for (int i = 0; i < TABLE_SIZE;i++){
        if(hash_table[i].value!=EMPTY){
            printf("hash index = %d, value = %d, index = %d\n", i, hash_table[i].value, hash_table[i].index);
        }
    }
}

int main(){
    int nums[] = {2,7,11,15};
    int returnSize;
    int target = 9;
    int *result = twoSum(nums, sizeof(nums) / sizeof(int), target, &returnSize);
    printf("%d %d\n", result[0], result[1]);
    print_hash_table();
    return 0;
}