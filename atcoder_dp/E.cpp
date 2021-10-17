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
int n,W;
int v[N],w[N];
ll dp[N];

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    cin >> n >> W;
    FOR(i,1,n) cin >> w[i] >> v[i];
    FOR(i,1,1000*n)
        dp[i]=INF;
    int ans = 0;
    FOR(i,1,n)
        FOD(j,1000*i,v[i]) {
            dp[j]=min(dp[j],dp[j - v[i]] + w[i]);
            if (dp[j]<=W)
                ans = max(ans,j);
        }
    cout << ans;
}