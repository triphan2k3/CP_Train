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

const int N=8e5+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int p[N][21];
int h[N],f[N],dp[N];
int ans,n;
vector<int> e[N],hz[N];

void dfs(int u,int par) {
    for (int v:e[u]) {
        if (v==par) continue;
        p[v][0] = u;
        h[v]=h[u]+1;
        dfs(v,u);
    }
}
 
void setup() {
    FOR(k,1,18)
        FOR(u,1,n)
            if (h[u] >= 1<<k)
            p[u][k]=p[p[u][k-1]][k-1];
}
 
int LCA(int u,int v) {
    if (h[v]<h[u])
        swap(u,v);
    FOD(i,18,0)
        if (h[v]-(1<<i) >= h[u])
            v=p[v][i];
    if (u==v)
        return u;
    FOD(i,18,0)
        if (h[u] >= (1<<i) && p[u][i]!=p[v][i]) {
            u=p[u][i];
            v=p[v][i];
        }
    return p[u][0];
}

void DFS(int u,int par) {
    dp[u]=f[u];
    for(int v:e[u]) {
        if (v == par) continue;
        DFS(v,u);
        if (dp[v] > h[u]) ans++;
        dp[u] = min(dp[u],dp[v]);
    }
}
int main() {
    #ifdef TriPhan
        freopen("chainblock_input.txt","r",stdin);
        freopen("chainblock_output.txt","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t; cin >> t;
    FOR(q,1,t) {
        cin >> n;
        ans = 0;
        FOR(i,2,n) {
            int u,v;
            cin >> u >> v;
            e[u].pb(v);
            e[v].pb(u);
        }
        FOR(i,1,n) {
            int x;
            cin >> x;
            hz[x].pb(i);
        }
        h[1] = 1;
        dfs(1,0);
        setup();
        FOR(i,1,n) if (hz[i].size()) {
            int u = hz[i][0];
            for(int v:hz[i]) 
                u = LCA(u,v);
            for(int v:hz[i])
                f[v]=h[u];   
        }
        DFS(1,0);
        FOR(i,1,n) {
            e[i].clear();
            hz[i].clear();
        }
        cout << "Case #" << q << ": " << ans << "\n";        
    }
}