/*
The goal is to determine whether a path exists from one side of the canyon to the other using the soldiers' viewing range. We construct a graph where nodes represent soldiers and edges exist if two soldiers' view ranges overlap. Using BFS, we check if a soldier near the bottom can connect to a soldier near the top.

Algorithm
Input & Graph Construction:

Read the canyon dimensions and number of soldiers.
Store soldier positions in a map.
Construct a graph where an edge exists between two soldiers if their view overlaps (i.e., distance ≤ 200).
BFS Traversal:

Start from soldiers at the bottom (y ≤ 100).
Perform BFS, marking visited nodes.
If we reach a soldier near the top (w - y ≤ 100), return true (no escape possible).
Output Result:

If a path exists from bottom to top, print 1 (no escape).
Otherwise, print 0 (escape is possible).

*/
#define int long long
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, MOD = 1e9 + 7, MAX_DIST = 40000;
map<int, pair<int, int>> coordinates;
vector<vector<int>> g;
int l, w, n;
bool is_within_distance(int i, int j) {
    int dx = coordinates[i].first - coordinates[j].first;
    int dy = coordinates[i].second - coordinates[j].second;
    return (dx * dx + dy * dy) <= MAX_DIST;
}
bool bfs() {
    queue<int> q;
    vector<bool> vis(n, false);
    
    for (int i = 0; i < n; ++i) {
        if (coordinates[i].second <= 100) {
            q.push(i);
            vis[i] = true;
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                if (abs(w - coordinates[v].second) <= 100) return true;
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return false;
}
int32_t main() {
    cin >> l >> w >> n;
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> coordinates[i].first >> coordinates[i].second;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (is_within_distance(i, j)) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    cout << (bfs() ? "1\n" : "0\n");
    return 0;
}

