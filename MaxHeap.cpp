#include <stdio.h>

int arr[100];
int size = 0;


// dapatin parentnya
int getParent(int pos){
	return pos / 2;
}

// dapatin anakan kiri 
int getLeftChild(int pos){
	return pos * 2;
}

// dapatin anakan kanan
int getRightChild(int pos){
	return pos * 2 + 1;
}

// function utk tuker value
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert(int value){
	size++; //buat buletannya (node) / siapin size
	
	arr[size] = value; // assign value
	
	int currIdx = size; // ganti penamaan
	int parent = getParent(currIdx); // assign parent
	
	while(arr[currIdx] > arr[parent] && size > 1){ // apakah value current index > daripada parent
		// untuk size > 1 digunakan utk kasus pertama kali insert
		
		// swap
		swap(&arr[currIdx], &arr[parent]);
		
		// ganti current index untuk lanjut ngecheck
		currIdx = parent;
	}
}

void heapify(int pos){
	// kasih penamaan
	int max = pos;
	int leftChild = getLeftChild(pos);
	int rightChild = getRightChild(pos);
	
	//apabila leftchild lebih besar daripada top
	if(arr[leftChild] > arr[max] && leftChild <= size){
		max = leftChild;
	}
	
	if(arr[rightChild] > arr[max] && rightChild <= size){
		max = rightChild;
	}
	
	//check apakah maxnya ada keganti
	if(pos != max){
		//tuker
		swap(&arr[pos], &arr[max]);
		
		
		//lanjut check ke atas / recursive
		heapify(max);
	}
}

void extract(){
	// assign array atas ke array paling terakhir
	arr[1] = arr[size];
	
	// hilangin sizenya
	size--;
	
	
	// heapify
	heapify(1);
}

void print(){
	for(int i = 1; i <= size; i++){
		printf("%d ", arr[i]);
	}
	printf("\nmax value : %d\n", arr[1]);
}

int main(){
	insert(100);
	insert(105);
	insert(110);
	
	print();
	extract();
	print();
	
	insert(110);
	print();
	return 0;
}
