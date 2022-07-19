#include <unordered_map>
#include <list>
#include <queue>
#include <vector>

using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    vector<int> indegree(v);
    for (auto i : adj)
    {
        for (int j : i.second)
            indegree[j]++;
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for (int neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    return ans;
}

// https://www.codingninjas.com/codestudio/problems/topological-sort_982938
// T = O(v+e)
// S = O(v+e)