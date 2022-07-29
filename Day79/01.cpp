#include <vector>

using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != 1e9 && (dist[u] + w) < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // negative cycle check
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != 1e9 && (dist[u] + w) < dist[v])
            return -1; // negative loop exists
    }

    return dist[dest];
}

// https://www.codingninjas.com/codestudio/problems/bellmon-ford_2041977
// T = O(m*n)
// S = O(n)