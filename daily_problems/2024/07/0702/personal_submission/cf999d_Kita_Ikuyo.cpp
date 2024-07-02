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
    vector<int> a(n);
    vector<vector<int>> mp(m);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i] % m].push_back(i);
    }
    int ave = n / m;
    int ans = 0;
    for (int i = 0; i < 2 * m; i++) {
        int now = i % m;
        while (mp[now].size() > ave) {
            stk.push(mp[now].back());
            mp[now].pop_back();
        }
        while (mp[now].size() < ave) {
            if (stk.empty())
                break;
            int pos = stk.top();
            stk.pop();
            ans += (now - a[pos] % m + m) % m;
            a[pos] += (now - a[pos] % m + m) % m;
            mp[now].push_back(pos);
        }
    }
    cout << ans << endl;
    for (int i = 0;i < n;i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
