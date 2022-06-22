#include <stdio.h>
#define SIZE 10000

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *MaxHeap, int size, int i){
    int largest = i;
    int left_children = 2 * i + 1;
    int right_children = 2 * i + 2;

    if(left_children<size && MaxHeap[left_children]>MaxHeap[largest]) largest = left_children;
    if(right_children<size && MaxHeap[right_children]>MaxHeap[largest]) largest = right_children;

    //check need to swap or not?
    if(largest!=i){
        swap(&MaxHeap[i], &MaxHeap[largest]);
        heapify(MaxHeap, size, largest);
    }
}

void insert(int *MaxHeap, int element_to_insert, int *size){
    MaxHeap[*size] = element_to_insert;
    *size += 1;
    //loop to heapify
    int i;
    for (i = *size / 2 - 1; i >= 0;i--){
        heapify(MaxHeap, *size, i);
    }
}

void delete(int *MaxHeap, int *size){
    swap(&MaxHeap[0], &MaxHeap[*size - 1]);
    *size -= 1;
    for (int i = *size / 2 - 1; i >= 0;i--){
        heapify(MaxHeap, *size, i);
    }
}

int findKthLargest(int* nums, int numsSize, int k){
    int size = 0;
    int MaxHeap[SIZE];
    for(int i = 0; i < numsSize; i++){
        insert(MaxHeap, nums[i], &size);
    }

    while(k > 1){
        k--;
        delete(MaxHeap, &size);
    }

    return MaxHeap[0];
}