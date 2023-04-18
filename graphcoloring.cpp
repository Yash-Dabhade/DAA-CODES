// Time Complexity=O(n^2)
#include<iostream>
#include<limits.h>
using namespace std;

void chromatic(int G[100][100], int n) {
	int max, new_col, i, j, color_row[n];

	color_row[0] = 1;
	max = 1;
	new_col = 0;

	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (G[i][j]) {
				new_col = 1;
			}
			else {
				color_row[i] = color_row[j];
				new_col = 0;
				break;
			}
		}
		if (new_col == 1) {
			max = max + 1;
			color_row[i] = max;
		}
	}

	cout << "Max colors used: " << max << endl;
	cout << "Status" << endl;
	for (i = 0; i < n; i++) {
		cout << "Vertex: " << i + 1 << " = " << color_row[i] << endl;
	}

}

int main() {
	int G[100][100];
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int s, d;
		cin >> s >> d;
		G[s - 1][d - 1] = 1;
		G[d - 1][s - 1] = 1;
	}
	chromatic(G, v);
}