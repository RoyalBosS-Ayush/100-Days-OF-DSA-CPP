#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

template <typename T>
class graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        adj[u].push_back(v);
        if (!direction)
            adj[v].push_back(u);
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (T j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int nodes, edges;
    cout << "Enter number of Nodes: ";
    cin >> nodes;

    cout << "Enter number of Edges: ";
    cin >> edges;

    // 5 6 0 1 1 2 2 3 3 1 3 4 0 4
    graph<int> g;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.printAdjList();

    return 0;
}