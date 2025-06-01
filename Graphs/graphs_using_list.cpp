#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph
{

    map<int, list<int>> mp;

public:
    Graph()
    {
        cout << "Graph Initialized" << endl;
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, bool directed)
    {

        mp[u].push_back(v);
        if (!directed)
        {
            mp[v].push_back(u);
        }
    }

    // Function to print the graph

    void print()
    {

        for (auto i : mp)
        {
            cout << i.first << "->";

            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{

    Graph g;
    int n, e;
    cout << "Enter the number of nodes in the graph " << endl;
    cin >> n;
    cout << "Enter the  number of edges in the graph" << endl;
    cin >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, true);
    }
    g.print();
    return 0;

    return 0;
}