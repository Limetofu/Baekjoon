#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true;
    cout << node << " ";

    // ���� ��带 �湮 (���� ��ȣ�� ���� �ͺ��� Ž��)
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

        // ���� ��带 �湮 (���� ��ȣ�� ���� �ͺ��� Ž��)
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

    vector<vector<int>> graph(N + 1);  // �׷����� ���� ����Ʈ�� ���� (1������ N������ ���)

    // ���� �Է�
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // ����� ����
    }

    // �� ��忡 ����� ���� ��带 ���� (���� ��ȣ�� ���� ������� Ž���ϱ� ����)
    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS Ž��
    vector<bool> visited(N + 1, false);  // �湮 ���
    dfs(graph, visited, V);
    cout << endl;

    // BFS Ž��
    visited.assign(N + 1, false);  // �湮 ��� �ʱ�ȭ
    bfs(graph, visited, V);
    cout << endl;

    return 0;
}
