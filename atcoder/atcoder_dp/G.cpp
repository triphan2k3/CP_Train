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

const int N=1e5+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
vector<int> e[N];
int n,m,ans;
int vs[N], dp[N], deg[N];
void dfs(int u) {
    vs[u] = 1;
    for(int v:e[u]) {
        if (!vs[v]) dfs(v);
        dp[u]=max(dp[u],dp[v]+1);
    }
}
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    cin >> n >> m;
    FOR(i,1,m) {
        int u,v;
        cin >> u >> v;
        e[v].pb(u);
        deg[v++];
    }
    FOR(i,1,n) if (!deg[i]) {
        dfs(i);
        ans = max(ans,dp[i]);
    }
    cout << ans;
}