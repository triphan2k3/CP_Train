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
ll dp[18][N];
ll a[16][16];
ll c[N];
int n;

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
    FOR(i,0,n-1)
        FOR(j,0,n-1)
        cin >> a[i][j];
    int allmask = (1<<n) - 1;
    FOR(mask,1,allmask) {
        vector<int> id;
        FOR(i,0,n-1)
            if (mask & (1<<i)) 
                id.pb(i);
        ll cost = 0;
        for(int x:id)
            for(int y:id)
                cost+=a[x][y];
        c[mask]=cost/2;
        //cout << mask << " " << c[mask] << "\n";
        dp[1][mask] = c[mask];
    }
    FOR(i,2,n) 
        FOR(mask,1,allmask) {
            dp[i][mask]=-INF;
            for(int pre = (mask-1)&mask;pre>0;pre=(pre-1) & mask)
                if (dp[i-1][pre] != -INF)
                    dp[i][mask]=max(dp[i][mask],dp[i-1][pre]+c[mask^pre]); 

        }
    ll ans = -INF;
    FOR(i,1,n)
        ans = max(ans, dp[i][allmask]);
    cout << ans;
}