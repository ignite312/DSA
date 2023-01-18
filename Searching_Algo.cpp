#include <bits/stdc++.h>
using namespace std;

int lower_bound(int arr[], int N, int X) {
    int mid;
    int low = 0;
    int high = N;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (X <= arr[mid])high = mid;
        else low = mid + 1;
    }
    if(low < N && arr[low] < X)low++;
    return low;
}
int upper_bound(int arr[], int N, int X) {
    int mid;
    int low = 0;
    int high = N;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (X >= arr[mid])low = mid + 1;
        else high = mid;
    }
    if(low < N && arr[low] <= X)low++;
    return low;
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
