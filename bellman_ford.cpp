// Time Complexity : O (E V);
#include<iostream>
using namespace std;
#define INF 999999;

void bellman_ford(int G[][3], int V, int e, int src) {
	int dist[V];
	for (int i = 0; i < V; i++) {
		dist[i] = INF;
	}
	dist[src] = 0;

	for (int i = 0; i < V - 1; i++) {
		for (int j = 0; j < e; j++) {
			int u = G[j][0], v = G[j][1], w = G[j][2];
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
			}
		}
	}

	for (int j = 0; j < e; j++) {
		int u = G[j][0], v = G[j][1], w = G[j][2];
		if (dist[u] + w < dist[v]) {
			cout << "Graph contains negative cycle" << endl;
			return;
		}
	}

// printing the shortest path for each vertices
	cout << "Shortest path for each vertex: " << endl;
	for (int i = 0; i < v; i++) {
		cout << G[i][0] << " to " << G[i][1] << " = " << dist[i] << endl;
	}

}

int main() {
	int v, e;
	cout << "Enter the  number of Vertices :" << endl;
	cin >> v;
	cout << "Enter the number of Edges :" << endl;
	cin >> e;
	int G[e][3];
	for (int i = 0; i < e; i++) {
		int s, d, w;
		cout << "\nEnter source (u): ";
		cin >> s;
		cout << "\nEnter destination (v): ";
		cin >> d;
		// cout<< "\n Enter weight (w) : ";
		cin >> w;
		G[i][0] = s;
		G[i][1] = d;
		G[i][2] = w;
	}

	bellman_ford(G, v, e, 0);
	return 0;
}