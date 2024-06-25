#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define v 5

int graph[v][v] = {
	{0, 2, 0, 6, 0}, // 0
	{2, 0, 3, 8, 5}, // 1
	{0, 3, 0, 0, 7}, // 2
	{6, 8, 0, 0, 9}, // 3
	{0, 5, 7, 9, 0}, // 4
};

int findMin(int cost[v], bool set[v]){
	// intinya disini cari paling minimum 
	// pake greedy algorithm
	int minimum = INT_MAX;
	int index;
	
	for(int i = 0; i < v; i++){
		// kalo misalkan ternyata setnya blm ada (false) dan costnya levih kecil dari current minimum
		if(!set[i] && cost[i] < minimum){
			minimum = cost[i];
			index = i;
		}
	}
	return index;
}

void printAll(int parent[]){
	for(int i = 1; i < v; i++){
		printf("%d - %d -> %d \n", parent[i], i, graph[i][parent[i]]);
	}
}

void solve(){
	int parent[v];
	int cost[v];
	bool set[v];
	
	// inisialisasi jadi infinite 
	for(int i = 0; i < v; i++){
		set[i] = false;
		cost[i] = INT_MAX;
	}
	
	// tentuin startnya mau darimana
	int startPoint = 0;
	
	cost[startPoint] = 0;
	parent[startPoint] = -1;
	
	// v - 1 karena yang terakhir gaperlu dicari lagi
	for(int i = 0; i < v - 1; i++){
		int min = findMin(cost, set);
		
		// karna si i udah ketemu makanya jadi true
		set[i] = true;
		
		
		for(int j = 0; j < v; j++){
			// cari apakah graphnya ada, dan set nya masih false serta current graph(cost) kurang dari cost yang di loop
			if(graph[min][j] && !set[j] && graph[min][j] < cost[j]){
				parent[j] = min;
				cost[j] = graph[min][j];
			}
		}
	}
	
	printAll(parent);
}

int main(){
	solve();
	
	return 0;
}
