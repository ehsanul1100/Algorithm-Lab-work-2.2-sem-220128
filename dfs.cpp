#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false); 
    stack<int> stack;
    
    stack.push(start);
    visited[start] = true;

    cout << "DFS Traversal: ";

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();
        cout << current << " "; 

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                stack.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter the adjacency matrix (0 or 1):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "Enter the starting node (0 to " << n - 1 << "): ";
    cin >> start;

    DFS(graph, start);

    return 0;
}