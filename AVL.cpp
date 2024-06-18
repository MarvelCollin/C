#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk AVL tree
struct Node {
    int key; // Nilai kunci
    struct Node *left, *right; // Pointer ke anak kiri dan kanan
    int height; // Tinggi node
};

// Fungsi untuk membuat node baru
struct Node *createNode(int key) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    *newNode = (struct Node){key, NULL, NULL, 1}; // Inisialisasi node baru
    return newNode;
}

// Fungsi untuk mendapatkan nilai maksimum dari dua angka
int getMax(int a, int b) {
    return (a > b) ? a : b;
}

// Fungsi untuk mendapatkan tinggi dari sebuah node
int getHeight(struct Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        return node->height;
    }
}

// Fungsi untuk menghitung balance factor
int calculateBalance(struct Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        return getHeight(node->left) - getHeight(node->right);
    }
}

// Fungsi untuk rotasi kanan
struct Node* rightRotate(struct Node* node) {
    struct Node* tempKiri = node->left;
    struct Node* subKanan = tempKiri->right;

    tempKiri->right = node;
    node->left = subKanan;

    // Update tinggi node
    node->height = getMax(getHeight(node->left), getHeight(node->right)) + 1;
    tempKiri->height = getMax(getHeight(tempKiri->left), getHeight(tempKiri->right)) + 1;

    return tempKiri;
}

// Fungsi untuk rotasi kiri
struct Node* leftRotate(struct Node* node) {
    struct Node* tempKanan = node->right;
    struct Node* subKiri = tempKanan->left;

    tempKanan->left = node;
    node->right = subKiri;

    // Update tinggi node
    node->height = getMax(getHeight(node->left), getHeight(node->right)) + 1;
    tempKanan->height = getMax(getHeight(tempKanan->left), getHeight(tempKanan->right)) + 1;

    return tempKanan;
}

// Fungsi untuk menyisipkan data ke AVL tree
struct Node *insertData(struct Node* data, int key) {
    if (data == NULL) {
        return createNode(key);
    } else if (key < data->key) {
        data->left = insertData(data->left, key);
    } else if (key > data->key) {
        data->right = insertData(data->right, key);
    } else {
        return data;
    }

    // Update tinggi node
    data->height = 1 + getMax(getHeight(data->left), getHeight(data->right));

    int balance = calculateBalance(data);

    // Kondisi rotasi berdasarkan balance factor
    if (balance > 1) {
        if (key < data->left->key) {
            return rightRotate(data);
        } else if (key > data->left->key) {
            data->left = leftRotate(data->left);
            return rightRotate(data);
        }
    } else if (balance < -1) {
        if (key > data->right->key) {
            return leftRotate(data);
        } else if (key < data->right->key) {
            data->right = rightRotate(data->right);
            return leftRotate(data);
        }
    }

    return data;
}

// Fungsi untuk mendapatkan nilai terkecil (minimum) dalam subtree
struct Node* minValue(struct Node* node){
	struct Node* curr = node;
	
	// Cari node terkiri
	while(curr->left){
		curr = curr->left;
	}
	
	return curr;
}

// Fungsi untuk menghapus node dari AVL tree
struct Node* deleteNode(struct Node* root, int key){
	if(root == NULL){
		return NULL;
	}
	
	if(key < root->key){
		root->left = deleteNode(root->left, key);
	} else if(key > root->key){
		root->right = deleteNode(root->right, key);
	} else {
		if(root->left == NULL || root->right == NULL){
			struct Node* temp = root->left ? root->left : root->right;
			
			if(!temp){
				temp = root;
				root = NULL;
			} else {
				*root = *temp;
			}
			free(temp);	
		} else {
			struct Node* temp = minValue(root->right);
			
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}
	
	if(!root) return NULL;
	
	// Update tinggi node
	root->height = 1 + getMax(getHeight(root->left), getHeight(root->right));
	
	int balance = calculateBalance(root);
	
	// Kondisi rotasi berdasarkan balance factor
	if(balance > 1 && calculateBalance(root->left) >= 0){
		return rightRotate(root);	
	}
	
	if(balance > 1 && calculateBalance(root->left) < 0){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	
	if(balance < -1 && calculateBalance(root->right) <= 0){
		return leftRotate(root);
	}
	
	if(balance < -1 && calculateBalance(root->right) > 0){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	
	return root;
}

// Fungsi untuk mencetak in-order traversal dari AVL tree
void inOrder(struct Node *data, int space) {
    if (data == NULL) return;

    inOrder(data->left, space + 5);

    for (int i = 0; i < space; i++) printf("  ");
    printf("%d(%d)\n\n", data->key, data->height);

    inOrder(data->right, space + 5);
}

int main() {
    struct Node* treeBst = NULL;

    treeBst = insertData(treeBst, 542);
    treeBst = insertData(treeBst, 624);
    treeBst = insertData(treeBst, 753);
    treeBst = insertData(treeBst, 865);
    treeBst = insertData(treeBst, 975);

    inOrder(treeBst, 0);
    treeBst = deleteNode(treeBst, 975);
    
    inOrder(treeBst, 0);

    return 0;
}
