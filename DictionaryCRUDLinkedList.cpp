#include <stdio.h> // Library untuk input/output standar
#include <string.h> // Library untuk pengoperasian string
#include <stdlib.h> // Library untuk alokasi dan dealokasi memori

#define RESET   "\x1B[0m" // Definisi kode warna untuk mereset warna terminal
#define RED     "\x1B[31m" // Definisi kode warna merah untuk teks
#define GREEN   "\x1B[32m" // Definisi kode warna hijau untuk teks

// Struktur untuk node dalam antrian
struct QueueNode {
    char slang[50]; // Kata slang
    char desc[100]; // Deskripsi slang
    struct QueueNode* next; // Pointer ke node berikutnya
};

// Struktur untuk kamus slang
struct Dictionary {
    struct QueueNode *head, *tail; // Pointer ke kepala (head) dan ekor (tail) antrian
};

struct Dictionary* dict; // Deklarasi kamus slang

// Fungsi untuk membuat kamus slang kosong
struct Dictionary* createDictionary() {
    struct Dictionary* dict = (struct Dictionary*)malloc(sizeof(struct Dictionary)); // Alokasi memori untuk kamus
    dict->head = dict->tail = NULL; // Inisialisasi kepala dan ekor kamus menjadi NULL
    return dict; // Mengembalikan pointer ke kamus yang dibuat
}

// Fungsi untuk memeriksa apakah kamus kosong
int isEmpty() {
    return (dict->head == NULL); // Mengembalikan 1 jika kepala kamus NULL, 0 jika tidak
}

// Fungsi untuk menambahkan kata slang ke dalam antrian
void insertQueue(char slang[], char desc[]) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode)); // Alokasi memori untuk node baru
    strcpy(newNode->slang, slang); // Salin kata slang ke node baru
    strcpy(newNode->desc, desc); // Salin deskripsi slang ke node baru
    newNode->next = NULL; // Atur pointer node baru ke NULL

    if (isEmpty()) { // Jika kamus kosong
        dict->head = dict->tail = newNode; // Atur kepala dan ekor kamus ke node baru
        return; // Keluar dari fungsi
    }

    dict->tail->next = newNode; // Atur pointer dari node terakhir ke node baru
    dict->tail = newNode; // Atur ekor kamus ke node baru
}

// Fungsi untuk menampilkan semua kata slang dalam kamus
void viewAll() {
    if(isEmpty()){ // Jika kamus kosong
        printf("Dictionary is empty.\n"); // Tampilkan pesan bahwa kamus kosong
        return; // Keluar dari fungsi
    }
    
    struct QueueNode* current = dict->head; // Pointer ke node pertama dalam kamus
    
    printf("Slang words in the dictionary:\n"); // Tampilkan judul untuk kata slang dalam kamus
    while(current != NULL){ // Selama masih ada node dalam kamus
        printf("%s%s%s -> %s%s%s\n", GREEN, current->slang, RESET, GREEN, current->desc, RESET); // Tampilkan kata slang dan deskripsinya
        current = current->next; // Pindah ke node berikutnya
    }
}

// Fungsi untuk keluar dari program
void exitProgram() {
    printf("Goodbye!\n"); // Tampilkan pesan selamat tinggal
    exit(0); // Keluar dari program
}

// Fungsi untuk menampilkan menu dan mengolah pilihan pengguna
void menu();

// Fungsi untuk menambahkan kata slang baru ke dalam kamus
void insert() {
    char slang[100]; // Variabel untuk menyimpan kata slang
    char desc[100]; // Variabel untuk menyimpan deskripsi slang
    
    do { // Lakukan
        printf("Input a slang word [%sno space && more than 1 character%s] > ", RED, RESET); // Tampilkan pesan untuk memasukkan kata slang
        scanf(" %[^\n]", slang); // Baca kata slang dari input pengguna
        getchar(); // Hapus karakter newline dari buffer
        
        // Ulangi jika panjang kata slang kurang dari 2 karakter atau mengandung spasi
    } while(strlen(slang) < 2 || strchr(slang, ' '));

    do { // Lakukan
        printf("Input %s%s%s description [%smust be more than 2 words%s] > ", GREEN, slang, RESET, RED, RESET); // Tampilkan pesan untuk memasukkan deskripsi slang
        scanf(" %[^\n]", desc); // Baca deskripsi slang dari input pengguna
        getchar(); // Hapus karakter newline dari buffer
        
        // Ulangi jika deskripsi tidak mengandung spasi
    } while(strchr(desc, ' ') == NULL);
    
    insertQueue(slang, desc); // Masukkan kata slang dan deskripsi ke dalam kamus
    printf("Successfully inserted \"%s%s%s\" with description \"%s%s%s\"\n", GREEN, slang, RESET, GREEN, desc, RESET); // Tampilkan pesan sukses
    menu(); // Kembali ke menu utama
}

// Fungsi untuk mencari kata slang dalam kamus
void search() {
    char slang[100]; // Variabel untuk menyimpan kata slang
    
    printf("Input slang word to search for: "); // Tampilkan pesan memasukkan kata slang yang ingin dicari
    scanf(" %[^\n]", slang); // Baca kata slang dari input pengguna
    getchar(); // Hapus karakter newline dari buffer
    
    struct QueueNode* current = dict->head; // Pointer ke node pertama dalam kamus
    int found = 0; // Variabel untuk menandai apakah kata slang ditemukan atau tidak
    while(current != NULL){ // Selama masih ada node dalam kamus
        if(strcmp(current->slang, slang) == 0) { // Jika kata slang ditemukan
            printf("Slang: %s%s%s, Description: %s%s%s\n", GREEN, current->slang, RESET, GREEN, current->desc, RESET); // Tampilkan kata slang dan deskripsinya
            found = 1; // Tandai bahwa kata slang ditemukan
            break; // Keluar dari loop
        }
        current = current->next; // Pindah ke node berikutnya
    }
    if (!found) { // Jika kata slang tidak ditemukan
        printf("Slang not found in the dictionary.\n"); // Tampilkan pesan bahwa kata slang tidak ditemukan
    }
}

// Fungsi untuk mencari kata slang dalam kamus berdasarkan awalan
void searchByPrefix() {
    char prefix[100]; // Variabel untuk menyimpan awalan kata slang
    printf("Input prefix to search for: "); // Tampilkan pesan memasukkan awalan yang ingin dicari
    scanf(" %[^\n]", prefix); // Baca awalan dari input pengguna
    getchar(); // Hapus karakter newline dari buffer
    
    struct QueueNode* current = dict->head; // Pointer ke node pertama dalam kamus
    int found = 0; // Variabel untuk menandai apakah ada kata slang yang ditemukan dengan awalan yang dicari
    while(current != NULL){ // Selama masih ada node dalam kamus
        if(strncmp(current->slang, prefix, strlen(prefix)) == 0) { // Jika kata slang memiliki awalan yang sesuai
            printf("Slang: %s%s%s, Description: %s%s%s\n", GREEN, current->slang, RESET, GREEN, current->desc, RESET); // Tampilkan kata slang dan deskripsinya
            found = 1; // Tandai bahwa ada kata slang yang ditemukan dengan awalan yang dicari
        }
        current = current->next; // Pindah ke node berikutnya
    }
    if (!found) { // Jika tidak ada kata slang yang ditemukan dengan awalan yang dicari
        printf("No slang words found in the dictionary with the given prefix.\n"); // Tampilkan pesan bahwa tidak ada kata slang yang ditemukan dengan awalan yang dicari
    }
}

// Fungsi untuk menampilkan menu dan mengolah pilihan pengguna
void menu() {
    int choice; // Variabel untuk menyimpan pilihan pengguna
    do { // Lakukan
        printf("\nMain Menu\n"); // Tampilkan judul menu
        printf("1. Release a new slang word\n"); // Tampilkan opsi untuk menambahkan kata slang baru
        printf("2. Search a slang word\n"); // Tampilkan opsi untuk mencari kata slang
        printf("3. View all slang words starting with a certain prefix\n"); // Tampilkan opsi untuk mencari kata slang dengan awalan tertentu
        printf("4. View all slang words\n"); // Tampilkan opsi untuk menampilkan semua kata slang dalam kamus
        printf("5. Exit\n"); // Tampilkan opsi untuk keluar dari program
        printf("Input your choice [1-5]: "); // Tampilkan pesan memasukkan pilihan
        scanf("%d", &choice); // Baca pilihan pengguna
        getchar(); // Hapus karakter newline dari buffer
        switch(choice){ // Periksa pilihan pengguna
            case 1: // Jika pilihan adalah 1
                insert(); // Panggil fungsi untuk menambahkan kata slang baru
                break; // Keluar dari switch
            case 2: // Jika pilihan adalah 2
                search(); // Panggil fungsi untuk mencari kata slang
                break; // Keluar dari switch
            case 3: // Jika pilihan adalah 3
                searchByPrefix(); // Panggil fungsi untuk mencari kata slang dengan awalan tertentu
                break; // Keluar dari switch
            case 4: // Jika pilihan adalah 4
                viewAll(); // Panggil fungsi untuk menampilkan semua kata slang dalam kamus
                break; // Keluar dari switch
            case 5: // Jika pilihan adalah 5
                exitProgram(); // Panggil fungsi untuk keluar dari program
                break; // Keluar dari switch
            default: // Jika pilihan tidak valid
                printf("Invalid choice! Please enter a number between 1 and 5.\n"); // Tampilkan pesan bahwa pilihan tidak valid
        }
    } while(choice != 5); // Ulangi selama pilihan pengguna bukan 5
}

// Fungsi utama program
int main() {
    dict = createDictionary(); // Buat kamus kosong
    
    // Masukkan beberapa kata slang awal ke dalam kamus
    insertQueue("LOL", "Laughing Out Loud");
    insertQueue("BRB", "Be Right Back");
    insertQueue("IDK", "I Don't Know");
    
    menu(); // Tampilkan menu utama
    
    return 0; // Selesai
}
