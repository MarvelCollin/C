#include<stdio.h>

int arr[100];
int size = 0;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int parent(int currentIndex){
	return currentIndex / 2;
}

int getLeftChild(int pos){
	return pos * 2;
}

int getRightChild(int pos){
	return pos * 2 + 1;
}

void insert(int value){
	size++;
	
	arr[size] = value; 
	
	int currentIndex = size;

	while(arr[currentIndex] < arr[parent(currentIndex)] && currentIndex > 1){
		swap(&arr[currentIndex] , &arr[parent(currentIndex)]);
		
		currentIndex = parent(currentIndex);
	}
}

void heapify(int pos){
	int least = pos;
	int leftChild = getLeftChild(pos);
	int rightChild = getRightChild(pos);
	
	if(leftChild <= size && arr[leftChild] < arr[least]){
		least = leftChild;
	}
	
	if(rightChild <= size && arr[rightChild] < arr[least]){
		least = rightChild;
	}
	
	if(least != pos){
		swap(&arr[least], &arr[pos]);
		
		heapify(least);
	}
}

void extract(){
	int min = arr[1];
	arr[1] = arr[size];
	
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
	insert(30);
	insert(50);
	insert(120);
	
	print();
	
	extract();
	
	print();
	
	return 0;
	
}
