#include<stdio.h>

int arr[100];
int size = 0;

// function utk swap
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
// get parent
int parent(int currentIndex){
	//       1
	//     2  3
	
	// parent dari idx 2 adalah 1
	// idx / 2 
	// 2 / 2 = 1
	return currentIndex / 2;
}

int getLeftChild(int pos){
	//       1
	//     2  3
	
	// left child dari idx 1 adalah 2
	// 1 * 2 -> 2
	return pos * 2;
}

int getRightChild(int pos){
	//       1
	//     2  3
	
	// right child dari idx 1 adalah 3
	// 1 * 2 + 1 -> 3
	return pos * 2 + 1;
}

void insert(int value){
	// tambahkan tempat kosong
	size++;
	
	arr[size] = value; // masukin tmpt kosong tadi dgn value
	
	int currentIndex = size; // dapatkan curr idx (supaya bisa diganti ganti)
	
	// ngecek selama curridx > parentnya serta curridx > 1 karna menghindari
	// insert yang pertama kali
	while(arr[currentIndex] > arr[parent(currentIndex)] && currentIndex > 1){
		// tuker si valuenya
		swap(&arr[currentIndex] , &arr[parent(currentIndex)]);
		
		// naikin di curridx menjadi parent
		currentIndex = parent(currentIndex);
	}
}

void heapify(int pos){
	// initialize dulu
	int largest = pos;
	int leftChild = getLeftChild(pos);
	int rightChild = getRightChild(pos);
	
	// compare left child sama si index largest
	if(leftChild <= size && arr[leftChild] > arr[largest]){
		// ganti indexnya
		largest = leftChild;
	}
	
	// compare right child sama si index largest
	if(rightChild <= size && arr[rightChild] > arr[largest]){
		// ganti indexnya
		largest = rightChild;
	}
	
	// cek apakah kondisi tadi ada yang keganti ?
	if(largest != pos){
		// tuker valuenya
		swap(&arr[largest], &arr[pos]);
		
		// recursive
		heapify(largest);
	}
}

void extract(){
	int max = arr[1];
	arr[1] = arr[size];
	
	// buang value yang terakhir
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
