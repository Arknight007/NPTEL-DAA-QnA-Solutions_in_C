import sys
import heapq
def main():
    data = list(map(int, sys.stdin.read().split()))
    idx = 0
    M = data[idx]
    idx += 1
    A = data[idx]
    idx += 1
    B = data[idx]
    idx += 1
    if A == B:
        print("YES")
        print(0)
        return
    max_node = 2000
    adj = [[] for _ in range(max_node + 1)]
    for _ in range(M):
        X = data[idx]
        Y = data[idx + 1]
        Z = data[idx + 2]
        idx += 3
        adj[X].append((Z, Y))
        adj[Z].append((X, Y))
    INF = float('inf')
    dist = [INF] * (max_node + 1)
    dist[A] = 0
    heap = []
    heapq.heappush(heap, (0, A))
    while heap:
        current_dist, u = heapq.heappop(heap)
        if u == B:
            break
        if current_dist > dist[u]:
            continue
        for v, w in adj[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heapq.heappush(heap, (dist[v], v))
    if dist[B] != INF:
        print("YES")
        print(dist[B])
    else:
        print("NO")
if __name__ == "__main__":
    main()