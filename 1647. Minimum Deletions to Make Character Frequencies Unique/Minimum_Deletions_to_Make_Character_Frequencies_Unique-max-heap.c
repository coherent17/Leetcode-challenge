#define SIZE 100000
int MaxHeap[SIZE];

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

int minDeletions(char * s){
    int frequency[26] = {0};
    for(int i = 0; i < strlen(s); i++){
        frequency[s[i]-'a']++;
    }

    int res = 0;
    int size = 0;
    for(int i = 0; i < 26; i++){
        if(frequency[i] != 0) insert(MaxHeap, frequency[i], &size);
    }

    while(size > 1){
        int popElement = MaxHeap[0];
        delete(MaxHeap, &size);
        if(popElement == MaxHeap[0]){
            if(popElement - 1 > 0){
                insert(MaxHeap, popElement - 1, &size);
            }
            res++;
        }
    }
    return res;
}