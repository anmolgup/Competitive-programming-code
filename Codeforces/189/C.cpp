#include <vector>
#include <iostream>

using namespace std;
int main() {

    int n; cin >> n;
    vector<int> a(n + 1); for (int i = 1; i <= n ; i++) cin >> a[i];
    vector<int> ind(n + 1, 0);
    vector<int> b(n + 1); for (int i = 1; i <= n; i++) cin >> b[i], ind[b[i]] = i;

    int i = 1;
    while (i < n and ind[a[i + 1]] > ind[a[i]]) i++;
    cout << n - i;

    return 0;
}