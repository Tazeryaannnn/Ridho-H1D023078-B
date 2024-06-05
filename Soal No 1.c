#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa {
    int NIM;
    char nama[50];
    float IPK;
} Mahasiswa;

typedef struct Node {
    Mahasiswa data;
    struct Node* next;
} Node;

Node* first = NULL;

Node* alokasikan(int NIM, char* nama, float IPK) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data.nama, nama);
    newNode->data.NIM = NIM;
    newNode->data.IPK = IPK;
    newNode->next = NULL;
    return newNode;
}

void insertLast(Node* p) {
    if (first == NULL) {
        first = p;
    } else {
        Node* temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void cetak() {
    Node* temp = first;
    while (temp != NULL) {
        printf("NIM: %d, Nama: %s, IPK: %.2f\n", temp->data.NIM, temp->data.nama, temp->data.IPK);
        temp = temp->next;
    }
}

void sortList() {
    Node* sorted = NULL;
    Node* current = first;
    while (current != NULL) {
        Node* next = current->next;
        insertAscending(&sorted, current);
        current = next;
    }
    first = sorted;
}

void insertAscending(Node** sorted, Node* newNode) {
    if (*sorted == NULL || newNode->data.NIM < (*sorted)->data.NIM) {
        newNode->next = *sorted;
        *sorted = newNode;
        return;
    }
    Node* current = *sorted;
    while (current->next != NULL && current->next->data.NIM < newNode->data.NIM) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    Node* current;
    current = alokasikan(129, "Saki", 3.40);
    insertLast(current);
    current = alokasikan(130, "Desi", 3.20);
    insertLast(current);
    current = alokasikan(125, "Budi", 3.50);
    insertLast(current);
    current = alokasikan(128, "Siti", 3.70);
    insertLast(current);
    current = alokasikan(126, "Andi", 3.80);
    insertLast(current);

    printf("Setelah dihapus satu dari belakang:\n");
    cetak();
    printf("\nSetelah data diurutkan berdasarkan NIM:\n");
    sortList();
    cetak();

    return 0;
}