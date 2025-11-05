#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100];  
bool visited[100];     

// DFS (recursive)
void DFS(int node) {
    visited[node] = true;
    cout << node << " ";
    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            DFS(neighbor);
        }
    }
}

// BFS (using queue)
void BFS(int start, int V) {
    bool vis[100] = {false};
    queue<int> q;
    vis[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "\nDFS Traversal: ";
    for (int i = 0; i < V; i++) visited[i] = false; 
    DFS(start);

    cout << "\nBFS Traversal: ";
    BFS(start, V);

    return 0;
}

