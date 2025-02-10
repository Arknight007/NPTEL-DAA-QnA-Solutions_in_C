#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX_NODE = 2000;
const int INF = numeric_limits<int>::max();

void dijkstra(int A, int B, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(MAX_NODE + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    
    dist[A] = 0;
    heap.push(make_pair(0, A));
    
    while (!heap.empty()) {
        pair<int, int> top = heap.top();
        heap.pop();
        int current_dist = top.first;
        int u = top.second;
        
        if (u == B) break;
        if (current_dist > dist[u]) continue;
        
        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                heap.push(make_pair(dist[v], v));
            }
        }
    }
    
    if (dist[B] != INF) {
        cout << "YES\n" << dist[B] << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int M, A, B;
    cin >> M >> A >> B;
    
    if (A == B) {
        cout << "YES\n0\n";
        return 0;
    }
    
    vector<vector<pair<int, int>>> adj(MAX_NODE + 1);
    
    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        adj[X].push_back(make_pair(Z, Y));
        adj[Z].push_back(make_pair(X, Y));
    }
    
    dijkstra(A, B, adj);
    
    return 0;
}
