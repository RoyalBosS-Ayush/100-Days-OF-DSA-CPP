#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (int nbr : adj[node])
    {
        if (nbr == parent)
            continue;

        if (!vis[nbr])
        {
            dfs(nbr, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[nbr]);

            if (low[nbr] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
            low[node] = min(low[node], disc[nbr]);
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    int parent = -1;
    vector<int> disc(v);
    vector<int> low(v);
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> result;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(i, parent, timer, disc, low, result, adj, vis);
    }

    return result;
}

// https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026
// T = O(N + e)
// S = O(N)