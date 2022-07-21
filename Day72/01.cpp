#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    // step1: create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // step2: map parent using BFS
    unordered_map<int, int> parent;
    unordered_map<int, int> visited;

    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int neighbour : adj[front])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }

    // step3: get answer using mapped parent
    vector<int> ans;
    int curr = t;
    ans.push_back(curr);

    while (curr != s)
    {
        curr = parent[curr];
        ans.push_back(curr);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297
// T = O(v+e)
// S = O(v+e)