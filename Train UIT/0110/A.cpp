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
ll dp[13][10000];
ll a[13],b[13];
int called[10000];
ll value[10000];
int n,k;

ll call(int mask) {
    if (called[mask]) return value[mask];
    vector<ll> x,y;
    FOr(i,0,n) if (mask & (1<<i)) {
        x.pb(a[i]);
        y.pb(b[i]);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    ll xt = x[x.size()/2];
    ll yt = y[y.size()/2];
    ll ans = 0;
    for (ll u:x)
        ans += abs(xt-u);
    for (ll v:y)
        ans += abs(yt-v);
    called[mask] = 1;
    value[mask] = ans;
    return ans;
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
    cin >> n >> k;
    if (k>n) k = n;
    FOR(i,0,n-1) cin >> a[i] >> b[i];
    int allmask = (1<<n) - 1;
    FOR(i,1,allmask) dp[0][i] = INF;
    FOR(i,1,k) {
        FOR(mask,1,allmask) {
            dp[i][mask]=INF;
            for(int pre = mask & (mask-1);pre >= 0; pre = (pre-1) & mask) {
                ll addtion = call(mask ^ pre);
                if (dp[i-1][pre]==INF) continue;
                dp[i][mask] = min(dp[i][mask],dp[i-1][pre]+addtion);
                if (pre==0) break;
            }
            //cout << i << " " << mask << " " << dp[i][mask] << "\n";
        }
    }
    cout << dp[k][allmask];
}