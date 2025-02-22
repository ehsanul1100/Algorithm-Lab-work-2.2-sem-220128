#include "bits/stdc++.h"
using namespace std;
int tsp_greedy(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    int cost = 0;
    int count = 0;
    cout << "Path: ";
    cout << 0 << " -> ";
    for (size_t i = 0; i < n;)
    {
        visited[i] = true;
        count++;
        int mini_index;
        int mini_cost = INT_MAX;
        for (size_t j = 0; j < n; j++)
        {
            if (graph[i][j] != 0 && !visited[j])
            {
                if (mini_cost > graph[i][j])
                {
                    mini_cost = graph[i][j];
                    mini_index = j;
                }
            }
        }

        if (count < n)
        {
            cout << mini_index << " -> ";
            i = mini_index;
            cost += mini_cost;
        }
        else if (count == n)
        {
            cost += graph[i][0];
            cout << 0 << "." << endl;
            break;
        }
    }
    return cost;
}
int main()
{
    int cities;
    cout << "Enter number of cities: ";
    cin >> cities;
    vector<vector<int>> graph(cities, vector<int>(cities, 0));
    cout << "Enter the adjacency matrix: " << endl;
    for (size_t i = 0; i < cities; i++)
    {
        for (size_t j = 0; j < cities; j++)
        {
            cin >> graph[i][j];
        }
    }
    int cost = tsp_greedy(graph);
    cout << cost << endl;
    return 0;
}
