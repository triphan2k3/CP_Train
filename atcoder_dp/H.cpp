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

const int N=1e3+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int a[N][N];
int dp[N][N];
int m,n;
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    cin >> m >> n;
    FOR(i,1,m) {
        string s; cin >> s;
        FOR(j,1,n)
            a[i][j] = (s[j-1] == '.');
    }
    dp[0][1]=1;
    FOR(i,1,m) FOR(j,1,n) if (a[i][j])
        dp[i][j] = (dp[i-1][j]+dp[i][j-1]) % MOD;
    cout << dp[m][n];
}