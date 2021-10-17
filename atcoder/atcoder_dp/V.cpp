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
int dp[N],dp2[N],pre[N],suf[N];
vector<int> a[N],deep[N];
int n,m;

void dfs(int u,int p) {
    dp[u] = 1;
    for(int v:a[u]) {
        if (v==p) continue;
        dfs(v,u);
        dp[u] = 1LL*dp[u]*(dp[v]+1) % m;
    }
}
void dfs2(int u,int p) {
    vector<int> adj;
    for(int v:a[u]) 
    if (v!=p) 
        adj.pb(v);
    pre[0] = suf[adj.size()+1] = 1;
    FOR(i,1,adj.size())
        pre[i]=1LL*pre[i-1]*(1+dp[adj[i-1]]) % m;
    FOD(i,adj.size(),1)
        suf[i]=1LL*suf[i+1]*(1+dp[adj[i-1]]) % m;
    FOR(i,1,adj.size()) {
        int v = adj[i-1];
        //cout << dp2[u] << pre[i-1] << suf[i+1] << "\n";
        dp2[v]=((1LL*dp2[u]*pre[i-1] % m)*suf[i+1]+1) % m;
    }
    for(int v:adj) dfs2(v,u);
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
    FOR(i,1,n-1) {
        int u,v; 
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs(1,0);
    dp2[1]=1;
    dfs2(1,0);
    FOR(i,1,n) {
        int ans = 1LL*dp[i]*dp2[i] % m;
        //cout << dp[i] << " " << dp2[i] << " " <<ans << "\n";
        cout << ans << "\n";
    }
}