#include "bits/stdc++.h"
#include "climits"
using namespace std;
// Kruskal's algorithm
struct Edge
{
    int src;
    int dest;
    int weight;
};

class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (size_t i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    void unite(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else
            {
                parent[rootU] = rootV;
                if (rank[rootU] == rank[rootV])
                {
                    rank[rootV]++;
                }
            }
        }
    }
};

// Prim's algorithm
int minKey(vector<int> &key, vector<bool> &visited)
{
    int minValue = INT_MAX;
    int min_index;

    int V = key.size();
    for (size_t v = 0; v < V; v++)
    {
        if (!visited[v] && key[v] < minValue)
        {
            minValue = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(vector<int> &parent, vector<vector<int>> graph)
{
    int V = graph.size();
    cout << "Edge \t Weitht \n";
    for (size_t i = 0; i < V; i++)
    {
        if (parent[i] != -1 && i != parent[i])
        {
            cout << parent[i] << " - " << i << "\t  " << graph[i][parent[i]] << endl;
        }
    }
}

void primMST(vector<vector<int>> &graph, int start)
{
    int V = graph.size();
    vector<int> parent(V);
    vector<int> key(V, INT_MAX);
    vector<bool> visited(V, false);

    key[0] = start;
    parent[start] = -1;

    for (size_t count = 0; count < V - 1; count++)
    {
        int u = minKey(key, visited);
        visited[u] = true;

        for (size_t v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    int V;
    cout << "Number of V : ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V, 0));
    for (size_t i = 0; i < V; i++)
    {
        for (size_t j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "Start V: ";
    cin >> start;
    primMST(graph, start);
    return 0;
}