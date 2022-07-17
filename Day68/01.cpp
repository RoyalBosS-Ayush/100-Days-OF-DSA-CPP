#include <unordered_map>
#include <list>
#include <vector>
#include <string>
#include <queue>

using namespace std;

bool isCyclicBFS(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    unordered_map<int, int> parent;

    parent[node] = -1;
    visited[node] = true;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front])
        {
            if (visited[neighbour] && neighbour != parent[front])
                return true;
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

bool isCyclicDFS(int node, int parent, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cyclic = isCyclicDFS(neighbour, node, adj, visited);
            if (cyclic)
                return true;
        }
        else if (parent != neighbour)
            return true;
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;

    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // bool cyclic = isCyclicBFS(i, adj, visited);
            bool cyclic = isCyclicDFS(i, -1, adj, visited);
            if (cyclic)
                return "Yes";
        }
    }

    return "No";
}

// https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670