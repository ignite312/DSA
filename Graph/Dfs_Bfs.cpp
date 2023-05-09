#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

class Queue {
    int arr[MAX];
    int front, rear, sz;
public:
    Queue() {front = rear = -1, sz = 0;}
    int get_front() {if(front != -1) return arr[front];}
    bool empty() {return (front == -1);}

    void push(int value) {
        if(empty())front = rear = 0;
        else rear++;
        arr[rear] = value;
        sz++;
    }
    void pop() {
        if(empty())return;
        sz--;
        if(front == rear)front = rear = -1;
        else front++;
    }
};

class Graph {
public:
    int vertices;
    int adjMatrix[MAX][MAX];
    bool visited[MAX];

    Graph(int v) {
        vertices = v;
        for (int i = 1; i <= vertices; i++)
            for(int j = 1; j <= vertices; j++)
                adjMatrix[i][j] = 0;
    }
    void init(){for(int i = 1; i <= vertices; i++)visited[i] = false;}
    void addEdge(int v1, int v2) {adjMatrix[v1][v2] = adjMatrix[v2][v1] = 1;}

    void dfs(int vertex) {
        cout << vertex << " ";
        visited[vertex] = true;
        for(int i = 1; i <= vertices; i++)
            if(adjMatrix[vertex][i] && !visited[i])
                dfs(i);
    }
    
    void bfs(int vertex) {
        Queue q;
        q.push(vertex);
        visited[vertex] = true;
        while(!q.empty()) {
            int now = q.get_front();
            cout << now << " ";
            q.pop();
            for(int i = 1; i <= vertices; i++) {
                if(adjMatrix[now][i] && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};
int main() {
    Graph G(6);

    G.addEdge(1, 4);
    G.addEdge(1, 5);
    G.addEdge(2, 5);
    G.addEdge(2, 3);
    G.addEdge(4, 6);
    G.init();
    G.dfs(1);
    cout << "\n";
    G.init();
    G.bfs(1);
    return 0;
}
