#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];

void bubbleSort(int arr[], int n) {
    int i, j;
    for(i = 0; i < n - 1; i++)
        for(j = 0; j < n - i - 1; j++)
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
void insertionSort(int arr[], int n) {
    int i, key, j;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for(i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx]) min_idx = j;
        if(min_idx != i)swap(arr[min_idx], arr[i]);
    }
}
void merge(int l, int r, int mid) {
    int l_sz = mid - l + 1;
    int r_sz = r - (mid + 1) + 1;
    int L[l_sz+1], R[r_sz+1];
    for(int i = 0; i < l_sz; i++) {
        L[i] = a[i+l];
    }
    for(int i = 0; i < r_sz; i++) {
        R[i] = a[i+mid+1];
    }
    L[l_sz] = R[r_sz] = INT_MAX;

    int l_i = 0, r_i = 0;
    for(int i = l; i <= r; i++) {
        if(L[l_i] <= R[r_i]) {
            a[i] = L[l_i];
            l_i++;
        }else {
            a[i] = R[r_i];
            r_i++;
        }
    }
    return;
}
void mergeSort(int l, int r) {
    if(l == r)return;
    int mid = l + (r - l)/2;
    mergeSort(l, mid);
    mergeSort(mid+1, r);
    merge(l, r, mid);
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
	int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)scanf("%d", &a[i]); 
	mergeSort(0, n-1);
	for(int i = 0; i < n; i++)printf("%d ", a[i]);
    return 0;
}
