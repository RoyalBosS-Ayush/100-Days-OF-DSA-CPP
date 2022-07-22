#include <unordered_map>
#include <list>
#include <set>
#include <vector>

using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    //     create adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // creating distance array
    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    // <distance, node>
    set<pair<int, int>> st;
    dist[source] = 0;

    st.insert(make_pair(0, source));
    while (!st.empty())
    {
        pair<int, int> top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for (auto neighbour : adj[topNode])
        {
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                if (record != st.end())
                {
                    st.erase(record);
                }

                dist[neighbour.first] = nodeDistance + neighbour.second;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}

// https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469
// T = O(elogv)
// S = O(L+v)