#include <unordered_map>
#include <list>
#include <queue>
#include <vector>

using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        adj[u].push_back(v);
    }

    vector<int> indegree(n);
    for (auto i : adj)
    {
        for (int j : i.second)
            indegree[j]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        count++;

        for (int neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    return count != n;
}

// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626