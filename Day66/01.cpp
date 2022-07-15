#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

void make_adjlist(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> edges, int vertex)
{
    for (auto i : edges)
    {
        int u = i.first;
        int v = i.second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (int i : adjList[front])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> visited;
    vector<int> ans;

    make_adjlist(adjList, edges, vertex);

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}

// https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002