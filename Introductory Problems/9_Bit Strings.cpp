#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define endl "\n"
#define int long long

int powerr(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
        {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y = y >> 1;
    }
    return res;
}

void func()
{
    int n;
    cin >> n;

    // find 2^n % mod
    cout << powerr(2, n) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        func();
    }
    return 0;
}