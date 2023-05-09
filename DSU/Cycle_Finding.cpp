#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)parent[i] = i;
    }
    int find_set(int v) {
        if (v == parent[v])return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) parent[b] = a;
    }
};
bool hasCycle(vector<vector<int>>& graph) {
    int n = graph.size();
    DSU uf(n);
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            if (uf.find_set(u) == uf.find_set(v))return true;
            uf.union_sets(u, v);
        }
    }
    return false;
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {0, 2}, {0, 1, 3}, {2}};
    if (hasCycle(graph))cout << "The graph has a cycle." << endl;
    else cout << "The graph is acyclic." << endl;
}
