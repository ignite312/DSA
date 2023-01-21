#include <bits/stdc++.h>
using namespace std;

int upper_bound(int a[], int n, int x) {
    int l = 0;
    int h = n;
    while (l < h) {
        int mid =  l + (h - l) / 2;
        if (x >= a[mid])l = mid + 1;
        else h = mid;
    }
    return l;
}
int lower_bound(int a[], int n, int x) {
    int l = 0;
    int h = n;
    while (l < h) {
        int mid =  l + (h - l) / 2;
        if (x <= a[mid])h = mid;
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
    return 0;
}
