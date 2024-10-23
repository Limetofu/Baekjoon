#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true;
    cout << node << " ";

    // 인접 노드를 방문 (정점 번호가 작은 것부터 탐색)
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}

void bfs(const vector<vector<int>>& graph, vector<bool>& visited, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // 인접 노드를 방문 (정점 번호가 작은 것부터 탐색)
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> graph(N + 1);  // 그래프를 인접 리스트로 저장 (1번부터 N번까지 사용)

    // 간선 입력
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // 양방향 간선
    }

    // 각 노드에 연결된 인접 노드를 정렬 (정점 번호가 작은 순서대로 탐색하기 위해)
    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS 탐색
    vector<bool> visited(N + 1, false);  // 방문 기록
    dfs(graph, visited, V);
    cout << endl;

    // BFS 탐색
    visited.assign(N + 1, false);  // 방문 기록 초기화
    bfs(graph, visited, V);
    cout << endl;

    return 0;
}
