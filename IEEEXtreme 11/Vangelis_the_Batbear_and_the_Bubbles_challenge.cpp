#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> a(n);
        map<ii,int> mp;
        int flag = 0;
        FOR(i,1,m) {
            int u,v;
            cin >> u >> v;
            flag |= u==v;
            a[u].pb(v);
            a[v].pb(u);
            flag |= mp[{u,v}];
            mp[{u,v}] = 1;
        }
        if (flag) {
            cout << "1\n";
            continue;
        }
        int component = 0;
        vector<int> valid(n,0);
        for(int i=0;i<n;i++) if (valid[i]==0) {
            valid[i] = 1;
            queue<int> q;
            q.push(i);
            while(q.size()) {
                int u = q.front();
                q.pop();
                for(int v:a[u])
                    if (!valid[v]) {
                        valid[v]=1;
                        q.push(v);
                    }
            }
            component++;
        }
        if (m>n-component)
            cout << "1\n";
        else cout << "0\n";
    }
}