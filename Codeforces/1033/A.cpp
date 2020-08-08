#include<iostream>
#include<vector>
#include<string>

#define pb push_back

using namespace std;

int n;
char chessboard[1005][1005];
bool visited[1005][1005];

void dfs(int srx, int sry) {

	visited[srx][sry] = true;

	for (int i = srx - 1; i <= srx + 1; i++) {
		for (int j = sry - 1; j <= sry + 1; j++) {
			if (visited[i][j] == false && chessboard[i][j] == '.')
				dfs(i, j);
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int ax, ay; cin >> ax >> ay;

	int bx, by; cin >> bx >> by;

	int cx, cy; cin >> cx >> cy;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			chessboard[i][j] = '.';
		}
	}
	for (int i = 1; i <= n; i++) chessboard[i][ay] = 'q';

	for (int j = 1; j <= n; j++) chessboard[ax][j] = 'q';
	//{-1,-1}, {-1,+1}, {+1,-1}, {+1,+1}

	int dir_i[] = { -1, -1, +1, +1};
	int dir_j[] = { -1, +1, -1, +1};
	for (int d = 0; d < 4; d++) {
		int r = ax;
		int c = ay;
		int dist = 1;
		while (r > 0 && r <= n && c > 0 && c <= n) {
			r = ax + dist * dir_i[d];
			c = ay + dist * dir_j[d];
			// cout<<r<<" "<<c<<endl;
			chessboard[r][c] = 'q';
			dist++;
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		cout << chessboard[i][j];
	// 	}
	// 	cout << endl;
	// }

	for (int i = 0; i < 1005; i++) {
		for (int j = 0; j < 1005; j++) visited[i][j] = false;
	}

	dfs(bx, by);

	cout << (visited[cx][cy] ? "YES" : "NO");

	return 0;
}