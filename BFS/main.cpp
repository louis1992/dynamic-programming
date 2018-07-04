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
    void BFS(int v);

private:
    int V;
    list<int> *adj;
};

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);    // Add w to v's list.
}

void Graph::BFS(int s) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; ++i)
        visited[i] = false;
    
    // Create a queue for BFS.
    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty()) {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (list<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
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
    g.BFS(2);
    
    return 0;
}
