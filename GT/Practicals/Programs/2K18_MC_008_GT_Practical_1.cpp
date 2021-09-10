#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    public:
        Graph(int V)
        {
            this->V = V;
            adj = new list<int>[V];
        }

        void addEdge(int u, int v)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int noOfVertices() { return this->V; }

        int countEdges()
        {
            int sum = 0;
            for (int i = 0; i < V; i++)
                sum += adj[i].size();
            return sum / 2;
        }

        int evenVertices()
        {
            int count = 0;
            for (int i = 0; i < this->V; i++)
            {
                if (adj[i].size() % 2 == 0)
                    count++;
            }
            return count;
        }

        int oddVertices()
        {
            return this->V - evenVertices();
        }
};

int main()
{
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(1, 4);

    cout << "Number of Vertices: " << g.noOfVertices() << endl;
    cout << "Number of Even Vertices: " << g.evenVertices() << endl;
    cout << "Number of Odd Vertices: " << g.oddVertices() << endl;
    cout << "Number of Edges: " << g.countEdges() << endl;

    return 0;
}
