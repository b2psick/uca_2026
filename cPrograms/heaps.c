#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value) {
    size++;

    int i = size;
    heap[i] = value;

    while (i > 1 && heap[i] > heap[i / 2]) {
        swap(&heap[i], &heap[i / 2]);
        i = i / 2;
    }
}

void createHeap(int arr[], int n) {
    size = 0;

    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }
}

void deleteRoot() {

    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }

    heap[1] = heap[size];
    size--;

    int i = 1;

    while (1) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        if (left <= size && heap[left] > heap[largest])
            largest = left;

        if (right <= size && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&heap[i], &heap[largest]);

        i = largest;
    }
}

void display() {
    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }

    printf("\n");
}

void heapSort() {

    int originalSize = size;

    for (int i = size; i > 1; i--) {

        swap(&heap[1], &heap[i]);

        size--;

        int root = 1;

        while (1) {
            int left = 2 * root;
            int right = 2 * root + 1;
            int largest = root;

            if (left <= size && heap[left] > heap[largest])
                largest = left;

            if (right <= size && heap[right] > heap[largest])
                largest = right;

            if (largest == root)
                break;

            swap(&heap[root], &heap[largest]);

            root = largest;
        }
    }

    size = originalSize;
}

int main() {

    int arr[] = {40, 10, 30, 50, 20, 60};
    int n = 6;

    createHeap(arr, n);

    printf("Max Heap: ");
    display();

    insert(70);
    display();

    deleteRoot();
    display();

    heapSort();
    display();

    return 0;
}