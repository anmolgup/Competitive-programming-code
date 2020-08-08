#include <cstdio>
#include <string>
#include <vector>

using namespace std;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector < string > ans(n, "");
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) {
      int sum = (i + j) & 1;
      if (sum == 0 && k > 0) {
        ans[i] += "L";
        k --;
      } else {
        ans[i] += "S";
      }
    }
  }
  if (k == 0) {
    puts("YES");
    for(int i = 0; i < n; i++)
      puts(ans[i].c_str());
  } else {
    puts("NO");
  }
}