
 #include <bits/stdc++.h>
using namespace std;
char G[55][55];
void ok() {
	printf("YES\n");
	exit(0);
}
void check() {
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) {
			if (G[i][j] == 'x' && G[i][j + 1] == 'x' && G[i][j + 2] == 'x') ok();
			if (G[i][j] == 'x' && G[i + 1][j] == 'x' && G[i + 2][j] == 'x') ok();
			if (G[i][j] == 'x' && G[i + 1][j + 1] == 'x' && G[i + 2][j + 2] == 'x') ok();
			if (j >= 2 && G[i][j] == 'x' && G[i + 1][j - 1] == 'x' && G[i + 2][j - 2] == 'x') ok();
		}
}
int main() {
	for (int i = 0; i < 4; ++i) scanf("%s", G[i]);
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) {
			if (G[i][j] == '.') {
				G[i][j] = 'x';
				check();
				G[i][j] = '.';
			}
		}
	printf("NO\n");
}