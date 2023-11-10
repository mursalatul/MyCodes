#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    // number of vertex
    int v;
    // store adjacene vertex
    vector<vector<int>> adj;

public:
    Graph(int v)
    {
        this->v = v;
        adj.resize(v);
    }

    void addEdge(int a, int b)
    {
        adj[a].push_back(b);
    }

    void BFS(int A)
    {
        // starting vertex
        int vr = A;

        // store visited vertexs
        vector<bool> visited(v, false);

        // making entered vertex visited
        visited[vr] = true;

        // create queue for BFS
        queue<int> qu;
        qu.push(vr);
        while (qu.size())
        {
            // printing first BFS in the queue
            vr = qu.front();
            cout << vr << ' ';
            qu.pop();

            // adding all the not printed adjacence of the element in the queue
            for (int ad_ele : adj[vr])
            {
                if (visited[ad_ele] == false)
                {
                    qu.push(ad_ele);
                    visited[ad_ele] = true;
                }
            }
        }
    }
};

int main()
{
    int sz;
    cout << "Number of vertex: ";
    cin >> sz;
    Graph gp(sz);
    int x;
    cout << "Edges: ";
    cin >> x;
    while (x--)
    {
        int a, b;
        cin >> a >> b;
        gp.addEdge(a,b);
    }
    int start;
    cout << "Start from: ";
    cin >> start;
    gp.BFS(start);
    return 0;
}
