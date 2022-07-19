#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

bool isCyclicDFS(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cyclic = isCyclicDFS(neighbour, adj, visited, dfsVisited);
            if (cyclic)
                return true;
        }
        else if (dfsVisited[neighbour])
            return true;
    }

    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool cyclic = isCyclicDFS(i, adj, visited, dfsVisited);
            if (cyclic)
                return 1;
        }
    }
    return 0;
}

// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626