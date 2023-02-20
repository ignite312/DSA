#include <bits/stdc++.h>
using namespace std;

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
void merge(int arr[], int l, int r, int mid) {
    int l_sz = mid - l + 1;
    int r_sz = r - (mid + 1) + 1;
    int L[l_sz+1], R[r_sz+1];
    for(int i = 0; i < l_sz; i++)L[i] = arr[i+l];
    for(int i = 0; i < r_sz; i++)R[i] = arr[i+mid+1];
    L[l_sz] = R[r_sz] = INT_MAX;
    int l_i = 0, r_i = 0;
    for(int i = l; i <= r; i++) {
        if(L[l_i] <= R[r_i]) {
            arr[i] = L[l_i];
            l_i++;
        }else {
            arr[i] = R[r_i];
            r_i++;
        }
    }
}
void mergeSort(int arr[], int l, int r) {
    if(l == r)return;
    int mid = l + (r - l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, r, mid);
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
void countingSort(int arr[], int n) {
    int ans[n], mx = arr[0];
    for(int i = 0; i < n; i++)
        if(arr[i] > mx)
            mx = arr[i];
    int cnt[mx+1];
    for(int i = 0; i <= mx; i++)cnt[i] = 0;
    for(int i = 0; i < n; i++)cnt[arr[i]]++;
    for(int i = 1; i <= mx; i++)cnt[i]+=cnt[i-1];
    for(int i = n - 1; i >= 0; i--) {
        ans[cnt[arr[i]] - 1] = arr[i];
        cnt[arr[i]]--;
    }
    for(int i = 0; i < n; i++)arr[i] = ans[i];
}
void bucketSort(int arr[], int n, int totalBucket) {
    int mx = INT_MIN, mn = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(arr[i] > mx)mx = arr[i];
        if(arr[i] < mn)mn = arr[i];
    }
    double range = (mx - mn)*1.0/totalBucket;
    vector<vector<int>> bucket(totalBucket);
    for(int i = 0; i < n; i++) {
        double diff = (arr[i]-mn)/range - (int)(arr[i]-mn)/range;
        if(diff == 0 && arr[i] != mn)
            bucket[(int)(arr[i]-mn)/range - 1].push_back(arr[i]);
        else bucket[(int)(arr[i]-mn)/range].push_back(arr[i]);
    }
    int k = 0;
    for(int i = 0; i < bucket.size(); i++)
        sort(bucket[i].begin(), bucket[i].end());
    for(int i = 0; i < bucket.size(); i++)
        for(int j = 0; j < bucket[i].size(); j++)
            arr[k++] = bucket[i][j];
    return;
}
void countingSortRadix(int arr[], int n, int exp) {
    int ans[n];
    int cnt[10];
    for(int i = 0; i < 10; i++)cnt[i] = 0;
    for(int i = 0; i < n; i++)cnt[(arr[i]/exp) % 10]++;
    for(int i = 1; i < 10; i++)cnt[i]+=cnt[i-1];
    for(int i = n - 1; i >= 0; i--) {
        ans[cnt[(arr[i]/exp) % 10] - 1] = arr[i];
        cnt[(arr[i]/exp) % 10]--;
    }
    for(int i = 0; i < n; i++)arr[i] = ans[i];
}
void radixSort(int arr[], int n) {
    int mx = arr[0];
    for(int i = 0; i < n; i++)
        if(arr[i] > mx)
            mx = arr[i];
    for(int exp = 1; mx/exp > 0; exp*=10)countingSortRadix(arr, n, exp);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)scanf("%d", &arr[i]); 
    quickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++)printf("%d ", arr[i]);
    return 0;
}
