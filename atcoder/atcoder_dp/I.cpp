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

const int N=3e3+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
ld a[N], dp[N];
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
    FOR(i,1,n) cin >> a[i]; //ngua
    dp[0]=1;
    FOR(i,1,n) {
        FOD(j,i,1) 
            dp[j]=dp[j-1]*a[i] + dp[j]*(1.0-a[i]);
        dp[0] = dp[0]*(1-a[i]);
    }
    ld ans=0;
    FOR(i,n/2 + 1,n)
        ans += dp[i];
    cout << setprecision(9) << fixed << ans;
}