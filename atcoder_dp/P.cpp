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
vector<int> a[N];
int dp[N][2];
int n;

void dfs(int u,int p) {
    dp[u][0]=dp[u][1]=1;
    for(int v:a[u]) if (v!=p) {
        dfs(v,u);
        dp[u][0] = (1LL*dp[u][0]*(dp[v][0]+dp[v][1])) % MOD;
        dp[u][1] = (1LL*dp[u][1]*dp[v][0]) % MOD;
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
    cin >> n;
    FOR(i,1,n-1) {
        int u,v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs(1,0);
    int ans = (dp[1][0]+dp[1][1]) % MOD;
    cout << ans;
}