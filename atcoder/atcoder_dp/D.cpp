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
int n,W;
ll dp[N];
int w[N],v[N];
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
    FOR(i,1,n)
        FOD(j,W,w[i])
            dp[j]=max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[W];
}