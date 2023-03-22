#include<bits/stdc++.h>
using namespace std;

class MinHeap {
    int *arr;
    int Mx, heapSize;
public:
    MinHeap(int n) {
        Mx = n;
        heapSize = 0;
        arr = new int[Mx];
    }
    int size() {return heapSize;}
    void heapify(int i) {
        int smallest = i, n = heapSize;
        int l = i*2 + 1;
        int r = i*2 + 2;
        if(l < n && arr[l] < arr[smallest])smallest = l;
        if(r < n && arr[r] < arr[smallest])smallest = r;
        if(smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }
    void insert(int key) {
        if(heapSize == Mx) {
            cout << "Overflow" << "\n";
            return;
        }
        heapSize++;
        int i = heapSize - 1;
        arr[i] = key;
        while(i != 0 && arr[(i - 1)/2] > arr[i]) {
            swap(arr[i], arr[(i - 1)/2]);
            i = (i - 1)/2;
        }
    }
    int removeMin() {
        if(heapSize == 0)return INT_MAX;
        if(heapSize == 1) {
            heapSize = 0;
            return arr[0];
        }
        int root = arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;
        heapify(0);
        return root;
    }
    void decreaseKey(int i, int new_key) {
        arr[i] = new_key;
        while(i != 0 && arr[(i-1)/2] > arr[i]) {
            swap(arr[(i-1)/2], arr[i]);
            i = (i-1)/2;
        }
    }
    void deleteKey(int i) {
        decreaseKey(i, INT_MIN);
        removeMin();
    }
    void display() {for(int i = 0; i < heapSize; i++)cout << arr[i] << " ";}
};
int main() {
    int n;
    cin >> n;
    MinHeap hp(n+5);
    for(int i = 0; i < n; i++) {
        int key;
        cin >> key;
        hp.insert(key);
    }
    cout << "Current Size: "<< hp.size() << "\n";
    hp.display();
    cout << "\n";

    hp.deleteKey(1);

    cout << "Current Size: "<< hp.size() << "\n";
    hp.display();
    cout << "\n";

    hp.insert(15);
    hp.insert(5);
    cout << "Current Size: "<< hp.size() << "\n";
}
