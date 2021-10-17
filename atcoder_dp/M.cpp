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
int dp[2][N],a[N];
int n,k;

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
    FOR(i,1,n) cin >> a[i];
    // dpij = dp[i-1][j...j-ai]
    // dpij-1 = dp[i-1][j-1...j-ai-1]
    // dpij = dpij-1 - dp[i-1][j-ai-1] + dp[i-1][j]
    dp[0][0] = dp[1][0] =1;
    FOR(i,1,n) {
        FOR(j,1,a[i])
            dp[i&1][j]=(dp[(i+1)&1][j]+dp[i&1][j-1]) % MOD;
        FOR(j,a[i]+1,k)
            dp[i&1][j]=(1LL*(dp[i&1][j-1]+dp[(i+1)&1][j]-dp[(i+1)&1][j-a[i]-1])+MOD) % MOD;
    }
    cout << dp[n%2][k];
}