#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Graph {
    // number of vertices
    int v;
    // edges
    vector<vector<int>> adj;
public:
    Graph (int nodes)
    {
        v = nodes;
        adj.resize(v);
    }

    // get edges
    void addEdge (int x, int y)
    {
        adj[x].push_back(y);
    }

    // print the dfs
    void DFS(int s)
    {
        // track visited nodes
        vector<bool> visited(v, false);

        // store the next node for visit
        stack<int> next_node;

        next_node.push(s);
        visited[s] = true;

        // loop untill the stack is empty
        while (!next_node.empty())
        {
            s = next_node.top();
            cout << s << ' ';
            next_node.pop();
            for (int x : adj[s])
            {
                if (visited[x] == false)
                {
                    next_node.push(x);
                    visited[x] = true;
                }
            }
        }
    }
};

int main()
{
    cout << "Nodes: ";
    int size;
    cin >> size;
    Graph g = Graph(4);

    cout << "Edges: ";
    int ed;
    cin >> ed;
    while (ed--)
    {
        int x, y;
        cout << ": ";
        cin >> x >> y;
        ob.addEdge(x, y);
    }
    g.DFS(2);
    return 0;
}