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
int a[N], b[N], c[N];
int dp[N][3];
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
    FOR(i,1,n)
        cin >> a[i] >> b[i] >> c[i];
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    dp[1][2] = c[1];
    FOR(i,1,n) {
        dp[i][0]=max(dp[i-1][1],dp[i-1][2]) + a[i];
        dp[i][1]=max(dp[i-1][2],dp[i-1][0]) + b[i];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1]) + c[i];
    }
    cout << max(dp[n][0],max(dp[n][1],dp[n][2]));
}