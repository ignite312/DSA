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
}
int main() {
	int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  
    }
	selectionSort(arr, n);
	for(int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
    return 0;
}
