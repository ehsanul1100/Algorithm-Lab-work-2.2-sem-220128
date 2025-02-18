#include "bits/stdc++.h"
using namespace std;

void dfs(vector<vector<int>> &graph, int start)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> stack;
    visited[start] = true;
    stack.push(start);
    cout << "DFS traversal: ";
    while (!stack.empty())
    {
        int current = stack.top();
        cout << current << " ";
        stack.pop();
        for (size_t i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                stack.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Vertiexs: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    cout << "Adjj Matriex: ";
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "Start Node: ";
    cin >> start;
    dfs(graph, start);
    return 0;
}
