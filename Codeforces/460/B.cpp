#include <bits/stdc++.h>

using namespace std;

inline int f(int64_t x)
{
    int ans = 0;
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t a, b, c;
    cin >> a >> b >> c;
    vector<long long> Ans;
    for (int i = 0; i < 81; i++)
    {
        int64_t num = 1;
        for (int j = 0; j < a; j++)
            num = num * (i + 1);
        num = num * b + c;
        if (num < 1000000000 && num > 0 && f(num) == i + 1)
            Ans.push_back(num);
    }
    sort(Ans.begin(), Ans.end());
    cout << Ans.size() << '\n';
    for (auto x : Ans)
        cout << x << ' ';
    return 0;
}