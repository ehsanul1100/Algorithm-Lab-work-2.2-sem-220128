#include "bits/stdc++.h"
using namespace std;
void bfs(vector<vector<int>> &graph, int start)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> queue;
    queue.push(start);
    visited[start] = true;
    cout << "BFS traversal: ";
    while (!queue.empty())
    {
        int current = queue.front();
        cout << current << " ";
        queue.pop();
        for (size_t i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                queue.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the number of verticex";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    cout << "Enter the adjjacency matrix: ";
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    int start;
    cout << "Enter starting verticex : ";
    cin >> start;
    bfs(graph, start);
    return 0;
}