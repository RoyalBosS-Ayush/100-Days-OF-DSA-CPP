#include <unordered_map>
#include <list>
#include <stack>
#include <vector>

using namespace std;

void topoSort(int node, vector<bool> &visited, unordered_map<int, list<int>> &adj, stack<int> &s)
{
    visited[node] = 1;

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
            topoSort(neighbour, visited, adj, s);
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    stack<int> s;
    vector<bool> visited(v);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            topoSort(i, visited, adj, s);
    }

    vector<int> ans;

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

// https://www.codingninjas.com/codestudio/problems/topological-sort_982938