#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long

#ifdef LOCAL
#include "C:\Program Files\DEBUG\debug.h"
#else
#define debug(...) 114514
#define ps 114514
#endif

signed main() {
    IOS int n, m;
    cin >> n >> m;
    int ans = n;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        debug(ans);
        ans = min(ans, r - l + 1);
    }
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= ans; j++) {
            if ((i - 1) * ans + j > n)
                break;
                debug(j);
            a[(i - 1) * ans + j] = j - 1;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
