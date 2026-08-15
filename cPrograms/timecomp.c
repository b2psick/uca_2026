#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void generateRandom(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % n + 1;
    }
}

void ascending(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

void descending(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = n - i; 
    }
}

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int* arr,int n) {
    for(int i = 0; i < n; i++) {
        int swapped = 0;
        for(int j = 0; j < n - i -1; j++){
            if(arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
                swapped = 1;
            }
        }
        if(swapped == 0) break;
    }
}

void selectionSort(int* arr,int n){
    for(int i = 0; i < n - 1; i++) {
        int min1 = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min1]) {
                min1 = j;
            }
        }
        if(min1 != i){
            swap(arr, min1 ,i);
        }
    }
}

void merge(int* arr, int left, int mid, int right, int* aux) {
    int i = left;
    int j = mid + 1;
    int k = left;
    while(i <= mid || j <= right) {
        if(i > mid) {
            aux[k++] = arr[j++];
        }else if(j > right) {
            aux[k++] = arr[i++];
        }else if(arr[i] > arr[j]) {
            aux[k++] = arr[j++];
        }else {
            aux[k++] = arr[i++];
        }
    }

    for(int i = left; i <= right; i++) {
        arr[i] = aux[i];
    }
}

void mergeSort(int* arr, int left, int right, int* aux) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, aux);
        mergeSort(arr, mid + 1, right, aux);
        merge(arr, left, mid, right, aux);
    }
}

int partition(int* arr, int left, int right) {
    int j = left;
    int pivot = arr[left];
    for(int i = left; i <= right; i++) {
        if(arr[i] < pivot) {
            j++;
            swap(arr, j, i);
        }
    }
    swap(arr, left, j);
    return j;
}

void quickSort(int* arr, int left, int right) {
    if(left < right) {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1); 
        quickSort(arr, pivot + 1, right); 
    }
}

int main() {
    struct timeval te;
    int size = 8000;
    int step = 4000;

    for(int i = 0; i < 8; i++) {
        int arr[size];
        generateRandom(arr, size);
        
        gettimeofday(&te,NULL);
        long long start = te.tv_sec * 1000LL + te.tv_usec/1000;
        quickSort(arr, 0, size - 1);
        gettimeofday(&te,NULL);
        long long end = te.tv_sec * 1000LL + te.tv_usec/1000;

        printf("%lld\n",end - start);
        size += step;
    }

    return 0;
}