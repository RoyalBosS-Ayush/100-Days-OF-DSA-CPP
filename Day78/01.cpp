#include <unordered_map>
#include <list>
#include <stack>
#include <vector>

using namespace std;

void revDfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;
    for (int nbr : adj[node])
    {
        if (!vis[nbr])
        {
            revDfs(nbr, vis, adj);
        }
    }
}

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;
    for (int nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfs(nbr, vis, s, adj);
        }
    }
    s.push(node);
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // topo sort
    stack<int> s;
    unordered_map<int, bool> vis;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, s, adj);
        }
    }

    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        vis[i] = false;
        for (int nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    int count = 0;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (!vis[top])
        {
            count++;
            revDfs(top, vis, transpose);
        }
    }
    return count;
}

// https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151