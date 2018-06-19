#include "header.hpp"

//void loadData(vector<vector<int>> data);
int minDistance(int dist[], bool sptSet[]);
int printSolution(int dist[], int n);
void dijkstra(int graph[9][9], int src);

int main(int argc, char**argv) {
	//vector<vector<int>> data;
	int graph[9][9] = {
		{0, 4, 0, 0, 0, 0, 0, 8, 0},
		{4, 0, 8, 0, 0, 0, 0, 11, 0},
		{0, 8, 0, 7, 0, 4, 0, 0, 2},
		{0, 0, 7, 0, 9, 14, 0, 0, 0},
		{0, 0, 0, 9, 0, 10, 0, 0, 0},
		{0, 0, 4, 14, 10, 0, 2, 0, 0},
		{0, 0, 0, 0, 0, 2, 0, 1, 6},
		{8, 11, 0, 0, 0, 0, 1, 0, 7},
		{0, 0, 2, 0, 0, 0, 6, 7, 0}
		};
	//loadData(graph);
	dijkstra(graph, 0);
	return 0;
}

//void loadData(vector<vector<int>> data) {
//}

void dijkstra(int graph[9][9], int src) {
	int dist[9];
	bool sptSet[9];

	for (int i = 0; i < 9; ++i)
		dist[i] = INT_MAX, sptSet[i] = false;
	dist[src] = 0;

	for (int count = 0; count < 9-1; ++count) {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;

		for (int v = 0; v < 9; ++v)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist, 9);
}

int minDistance(int dist[], bool sptSet[]) {
	int min = INT_MAX;
	int min_index;

	for (int v = 0; v < 9; ++v)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}

int printSolution(int dist[], int n) {
	cout << "Vertex Distance from Source" << endl;
	for (int i = 0; i < 9; ++i)
		cout << i << "      " << dist[i] << endl;
}