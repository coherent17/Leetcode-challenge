#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 20000
#define EMPTY -1000000001

int hash_table[TABLE_SIZE];


void init_hash_table(int *hash_table){
    for (int i = 0; i < TABLE_SIZE;i++){
        hash_table[i] = EMPTY;
    }
}

//hash function
int hash(int number){
    return (number > 0) ? (number * 2617) % TABLE_SIZE : (-number * 2617) % TABLE_SIZE;
}

//insert the number into hash table
void hash_table_insert(int number, int *hash_table){
    //calculate the index by hash function
    int index = hash(number);

    //find the open address in hash_table, when collision
    for (int i = 0; i < TABLE_SIZE;i++){
        int try = (i + index) % TABLE_SIZE;
        if(hash_table[try]==EMPTY){
            hash_table[try] = number;
            return;
        }
    }
}

//if found the element, return index, else return -1
int hash_table_lookup(int number, int *hash_table){
    int index = hash(number);
    for (int i = 0; i < TABLE_SIZE;i++){
        int try = (i + index) % TABLE_SIZE;
        if(hash_table[try]==EMPTY)
            return -1;
        if(hash_table[try]==number)
            return try;
    }
    return -1;
}

void print_hash_table(int *hash_table){
    for (int i = 0; i < TABLE_SIZE;i++){
        if(hash_table[i]!=EMPTY){
            printf("index = %d, value = %d\n", i, hash_table[i]);
        }
    }
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *result = malloc(sizeof(int) * (*returnSize));
    
    init_hash_table(hash_table);
    for (int i = 0; i < numsSize;i++){
        hash_table_insert(nums[i], hash_table);
    }

    int index;
    int i, j;
    for (i = 0; i < numsSize;i++){
        index = hash_table_lookup(target - nums[i], hash_table);
        if(index!=-1){
            result[0] = i;
            for (j = 0; j < numsSize;j++){
                if(j!=i && nums[j]==hash_table[index]){
                    result[1] = j;
                    break;
                }
            }
            break;
        }
        hash_table_insert(target - nums[i], hash_table);
    }
    return result;
}


int main(){
    int nums[] = {3,2,4};
    int returnSize;
    int target = 6;
    int *result = twoSum(nums, sizeof(nums) / sizeof(int), target, &returnSize);
    printf("%d %d\n", result[0], result[1]);
    return 0;
}