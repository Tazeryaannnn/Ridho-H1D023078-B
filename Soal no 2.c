#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100 // Ukuran maksimum stack

// Struktur data untuk stack
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Fungsi untuk menginisialisasi stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Fungsi untuk memeriksa apakah stack kosong
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Fungsi untuk memeriksa apakah stack penuh
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Fungsi untuk memasukkan elemen ke stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack penuh, tidak dapat menambahkan elemen.\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Fungsi untuk menampilkan deret Fibonacci hingga bilangan ke-n
void fibonacciSequence(int n) {
    Stack stack;
    initStack(&stack);
    push(&stack, 0); // Menyimpan nilai awal 0
    push(&stack, 1); // Menyimpan nilai awal 1

    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    printf("Deret Fibonacci hingga bilangan ke-%d: ", n);
    printf("%d %d ", 0, 1); // Menampilkan dua nilai awal

    for (int i = 2; i < n; i++) {
        int a = pop(&stack);
        int b = pop(&stack);
        int c = a + b;
        printf("%d ", c);
        push(&stack, b);
        push(&stack, c);
    }

    printf("\n");
}

int main() {
    fibonacciSequence(18); // Menghitung deret Fibonacci hingga bilangan ke-18
    return 0;
}