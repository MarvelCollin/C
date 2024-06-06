#include <stdio.h>
#include <stdlib.h>

// Definisi struktur Edge yang memiliki atribut dst, src, dan cost
struct Edge {
    int dst, src, cost;
};

// Fungsi pembanding yang digunakan untuk pengurutan menggunakan qsort
int compareQSort(const void* a, const void* b){
    return ((Edge*)a)->cost - ((Edge*)b)->cost;
}

// Fungsi untuk mencari parent dari suatu node dalam struktur disjoint set
int findParent(int *listD, int index){
    // Jika node tersebut adalah parent-nya sendiri, maka kembalikan index-nya
    if(listD[index] == index){
        return index;
    } else {
        // Jika bukan, maka rekursif mencari parent-nya
        return findParent(listD, listD[index]);
    }
}

// Fungsi untuk melakukan union (penggabungan) dua set
void unionD(int *listD, int i1, int i2){
    // Mengatur parent dari i1 menjadi parent dari i2
    listD[findParent(listD, i1)] = findParent(listD, i2);
}

// Fungsi utama untuk menyelesaikan masalah Kruskal
void solve(Edge *edge, int v, int e){
    // Mengurutkan edge berdasarkan cost-nya secara menaik
    qsort(edge, e, sizeof(Edge), compareQSort);
    
    // Inisialisasi disjoint set dengan setiap node sebagai parent-nya sendiri
    int listD[v];
    for(int i = 0; i < v; i++){
        listD[i] = i;
    }
    
    // Menyimpan hasil akhir (edge terpilih) dalam array result
    Edge result[v-1];
    int indexEdgeProblem = 0, indexResult = 0;
    
    // Iterasi selama hasil belum lengkap (v-1 edge)
    while(indexResult < v - 1){
        // Ambil edge berikutnya dari array edge yang telah diurutkan
        Edge currEdge = edge[indexEdgeProblem];
        indexEdgeProblem++;
        
        // Cari parent dari node sumber dan tujuan edge
        int p1 = findParent(listD, currEdge.src);
        int p2 = findParent(listD, currEdge.dst);
        
        // Jika parent-nya berbeda, maka edge tersebut dapat ditambahkan
        if(p1 != p2){
            // Simpan edge tersebut dalam hasil akhir
            result[indexResult] = currEdge;    
            indexResult++;
            
            // Lakukan union (penggabungan) dua set
            unionD(listD, p1, p2);
        }
    }
    
    // Tampilkan hasil akhir (edge terpilih)
    for(int i = 0; i < v - 1; i++){
        Edge currEdge = result[i];
        printf("%d - %d = %d\n", currEdge.src, currEdge.dst, currEdge.cost);
    }
}

int main(){
    // Contoh input
    int e = 5;
    int v = 4;

    Edge edge[e];
    edge[0] = (Edge){0,1,10};
    edge[1] = (Edge){0,2,6};
    edge[2] = (Edge){0,3,5};
    edge[3] = (Edge){1,3,15};
    edge[4] = (Edge){2,3,4};
    
    // Memanggil fungsi utama untuk menyelesaikan masalah
    solve(edge, v, e);
    
    return 0;
}
