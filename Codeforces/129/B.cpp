#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int min_array(int arr[], int n) {
	int min_element = INT_MAX;
	for (int i = 1; i <= n; i++) {
		min_element = min(min_element, arr[i]);
	}
	return min_element;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m; cin >> n >> m;
	int adj_mat[n + 1][n + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) adj_mat[i][j] = 0;
	}
	int deg[n + 1] = {0};
	int prev_deg[n + 1] = {0};
	for (int k = 0; k < m; k++) {
		int a, b; cin >> a >> b;
		adj_mat[a][b] = 1;
		deg[a]++;
		adj_mat[b][a] = 1;
		deg[b]++;
	}
	for (int i = 0; i <= n; i++) {
		if (deg[i] == 0) deg[i] = INT_MAX;
	}
	for (int i = 0; i <= n; i++) {prev_deg[i] = deg[i];}
	int cnt = 0;
	while (min_array(deg, n ) == 1) {
		// for (int i = 1; i <= n; i++)	cout << deg[i] << endl;
		// cout << "------------------------" << endl;
		cnt++;
		for (int i = 1; i <= n; i++) {
			if (deg[i] == 1 && prev_deg[i] == 1) {
				for (int j = 1; j <= n; j++) {
					if (adj_mat[i][j] == 1) {
						adj_mat[i][j] = 0;
						deg[i] = INT_MAX;
						adj_mat[j][i] = 0;
						deg[j]--;
						if (deg[j] == 0) deg[j] = INT_MAX;
					}
				}
			}
		}
		for (int i = 0; i <= n; i++) {
			prev_deg[i] = deg[i];
		}
	}
	cout << cnt;
	return 0;
}