#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define endl "\n"
#define int long long

void func()
{
    int n; cin >> n;

    //Legendre's formula -> power of prime p in n!
    int power = 0;
    int x = 5;
    while(x <= n) {
        power += (n / x);
        x *= 5;
    }

    cout << power << endl;
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