#include <bits/stdc++.h>
using namespace std;
int parent[1000+10];

void make_set(int v) {
    parent[v] = v;
    return;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
    return;
}
int main() {
    for(int i = 1; i <= 10; i++) make_set(i);
    union_sets(1, 8);
    cout << parent[1] << " " << parent[8] << '\n';
	return 0;
}
