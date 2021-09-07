#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 15000

typedef struct node{
    int value;
    int index;
    struct node *next;
} node;

node *hash_table[TABLE_SIZE];

void init_hash_table(){
    for (int i = 0; i < TABLE_SIZE;i++){
        hash_table[i] = NULL;
    }
}

int hash(int value){
    value = (value > 0) ? value : -value;
    return (value * 26) % TABLE_SIZE;
}

void insert_hash_table(int value, int index){
    int hash_index = hash(value);

    node *newnode = malloc(sizeof(node));
    newnode->value = value;
    newnode->index = index;
    newnode->next = NULL;

    //insert the newnode at head
    newnode->next = hash_table[hash_index];
    hash_table[hash_index] = newnode;
}

int hash_table_search(int value){
    int hash_index = hash(value);
    node *temp = hash_table[hash_index];
    while(temp!=NULL){
        if(temp->value==value)
            return temp->index;
        temp = temp->next;
    }
    return -1;
}

//time complexity: O(n)
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    init_hash_table();
    *returnSize = 2;
    int *result = malloc(sizeof(int)*(*returnSize));
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
        if(hash_table[i]!=NULL){
            node *temp = hash_table[i];
            printf("hash index = %d: ", i);
            while(temp!=NULL){
                printf("%d (index = %d) - ", temp->value, temp->index);
                temp = temp->next;
            }
            printf("\n");
        }
    }
    printf("\n");
}

int main(){
    int nums[]={2,7,11,15};
    int returnSize;
    int target = 18;
    int *result = twoSum(nums, sizeof(nums) / sizeof(int), target, &returnSize);
    printf("%d %d\n", result[0], result[1]);
    print_hash_table();
    return 0;
}