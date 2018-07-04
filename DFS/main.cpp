#include <iostream>
#include <list>

using namespace std;

// Graph class represents a directed graph.
class Graph {
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w);
    void DFS(int v);

private:
    int V;
    list<int> *adj;
    void DFS_util(int v, bool visited[]);
};

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);    // Add w to v's list.
}

void Graph::DFS_util(int v, bool visited[]) {
    // Mark the current node as visited.
    visited[v] = true;
    cout << v << " ";

    // Recur.
    for (list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS_util(*i, visited);
}

void Graph::DFS(int v) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; ++i)
        visited[i] = false;
    DFS_util(v, visited);

    /*
    for (int i = 0; i < V; ++i)
        if (visited[i] == false)
            DFS_util(i, visited);
    */
}

int main(int argc, char** argv) {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    //cout << g.DFS(2) << endl;
    g.DFS(2);
    
    return 0;
}
