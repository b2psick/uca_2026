#include <bits/stdc++.h>

using namespace std;

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
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

void quickSort(int* arr, int left, int right, int k) {
    if(left < right) {
        int pivot = partition(arr, left, right);
        if(pivot == k - 1) {
            return;
        }else if(pivot > k - 1) {
            quickSort(arr, left, pivot - 1, k);
        }else {
            quickSort(arr, pivot + 1, right, k);
        }
    }
}

int main() {
    int arr[100] = {1,2,3,4,33,1,1,2,3456,676,4,2,2,1,1,8,9,87,6,5};

    int k = 14;

    quickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, k);

    return 0;
}