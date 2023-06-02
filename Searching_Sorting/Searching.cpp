#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for(int i = 0; i < n; i++)
        if(arr[i] == x)
            return i;
    return -1;
}
int binarySearch(int arr[], int n, int x) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == x) return mid;
        if(arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
int binarySearchRecursive(int arr[], int x, int low, int high) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            return binarySearchRecursive(arr, x, mid + 1, high);
        else
            return binarySearchRecursive(arr, x, low, mid - 1);
    }
    return -1;
}
int upper_bound(int arr[], int n, int x) {
    int l = 0, h = n;
    while(l < h) {
        int mid =  l + (h - l) / 2;
        if (x >= arr[mid])l = mid + 1;
        else h = mid;
    }
    return l;
}
int lower_bound(int arr[], int n, int x) {
    int l = 0, h = n;
    while(l < h) {
        int mid =  l + (h - l) / 2;
        if(x <= arr[mid])h = mid;
        else l = mid + 1;
    }
    return l;
}
int main() {
	int n, target;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)scanf("%d", &arr[i]); 
    scanf("%d", &target);
    printf("%d\n", upper_bound(arr, n, target));
    printf("%d\n", lower_bound(arr, n, target));
    printf("%d\n", binarySearch(arr, n, target));
    printf("%d\n", linearSearch(arr, n, target));
    return 0;
}
