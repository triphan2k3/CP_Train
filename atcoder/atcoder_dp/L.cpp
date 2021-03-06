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
ll dp[N][N];
int a[N];
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
        cin >> a[i];
    FOR(len,1,n)
        FOR(i,1,n-len+1) {
            int j = i+len-1;
            if ((n-len) % 2) 
                dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1]-a[j]);
            else
                dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j-1]+a[j]);
        }
    cout << dp[1][n];
}