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
int dp[N][N];
int s[N];
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int n;
    cin >> n;
    string S;
    cin >> S;
    S = "##"+S;
    dp[1][1]=1;
    FOR(i,2,n) {
        FOR(j,1,i) s[j] = (s[j-1]+dp[i-1][j]) % MOD;
        FOR(j,1,i) 
        if (S[i]=='<')
            dp[i][j] = s[j-1];
        else
            dp[i][j] = (MOD + s[i] - s[j-1]) % MOD;
    }
    int ans = 0;
    FOR(i,1,n) ans = (ans + dp[n][i]) % MOD;
    cout << ans;
}