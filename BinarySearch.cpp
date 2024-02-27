#include <stdio.h>

// konsep : sama seperti mencari halaman pada sebuah buku tapi selalu dibagi 2
// binary search hanya boleh digunakan ketika arraynya sudah di sort

int binarySearch(int arr[], int kiri, int kanan, int x) {
    // selama value kiri tidak melebih atau sama dengan kanan, 
	// maka masih bisa melanjutkan
	while (kiri <= kanan) {
		// cari nilai tengahnya
        int tengah = (kanan + kiri) / 2;

		// nah jadi cara kerja si binary search selalu belah tengah
		// sampai menemukan si targetnya
        if (arr[tengah] == x)
            return tengah;

		// si value x lebih besar daripada value tengah
		// jika kita bayangkan halaman buku, maka misalkan target kita adalah halaman 90 
		// dan kita sedang dihalaman 70, berarti kita mau buka lembar kekanan dong
        if (arr[tengah] < x)
            kiri = tengah + 1; // nah ini gunanya untuk mengabaikan bagian kiri
            
        // Jika elemen lebih kecil dari nilai tengah, abaikan bagian kanan
        else
            kanan = tengah - 1;
    }
    
    // kalau gak ketemu
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    
    // rumus mencari size dari suatu array
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
	
	// n - 1 ??
	// karena n merupakan size, dan index dimulai dari 0 tapi size dari 1, maka
	// kita harus kurangi 1 supaya tidak kelewatan
    int hasil = binarySearch(arr, 0, n - 1, x);
    
    if (hasil != -1)
        printf("ada di : %d\n", hasil);
    else
        printf("ga ketemu coyyyyy\n");
    return 0;
}

