#include <stdio.h>

int arr[1000];
int size = 0;

int getParentIndex(int position){
    return position / 2;
}

int getLeftChild(int position){
    return position * 2;
}

int getRightChildren(int position){
    return position * 2 + 1;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value){
    size++;
    arr[size] = value;
    
    int currentIndex = size;
    int parent = getParentIndex(currentIndex);
    
    while(arr[currentIndex] > arr[parent] && currentIndex > 1){
        swap(&arr[currentIndex], &arr[parent]);
        currentIndex = parent;
        parent = getParentIndex(currentIndex);
    }
}

void heapify(int position){
    int max = position;
    int leftChildrenIndex = getLeftChild(position);
    int rightChildrenIndex = getRightChildren(position);
    
    if(arr[max] < arr[rightChildrenIndex]){
        max = rightChildrenIndex;
    }
    if(arr[max] < arr[leftChildrenIndex]){
        max = leftChildrenIndex;
    }
    
    if(max != position){
        swap(&arr[max], &arr[position]);
        heapify(max);
    }
}

void deleteHeap(){
    if(size == 0){
        printf("Heap empty");
        return;
    }
    
    arr[1] == arr[size];
    size--;
    
    heapify(1);
}

void print(){
    for(int i = 1; i <= size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    insert(100);
    insert(90);
    insert(80);
    insert(120);
    
    print();
    
    deleteHeap();
    print();
    
    return 0;
}
