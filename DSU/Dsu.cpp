#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int parent[N], size[N], rank[N];

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
    //rank[v] = 0;
}
int find_set(int v) {
    if (v == parent[v])return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if(size[a] < size[b])swap(a, b);
        parent[b] = a;
        size[a]+=size[b];
    }
}
// Union by Rank
// void union_sets(int a, int b) {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b) {
//         if (rank[a] < rank[b])
//             swap(a, b);
//         parent[b] = a;
//         if (rank[a] == rank[b])
//             rank[a]++;
//     }
// }
int main() {
    for(int i = 1; i <= 10; i++) make_set(i);
    union_sets(1, 8);
    cout << parent[1] << " " << parent[8] << '\n';
    return 0;
}
