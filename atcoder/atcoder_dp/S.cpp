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
int dp[10001][2][2][100];
int a[N];
int d;

int call(int i, int kt, int st, int md,int len) {
    if (dp[i][kt][st][md] != -1) return dp[i][kt][st][md];
    if (i == len) {
        dp[i][kt][st][md] = (st==1) && (md==0);
        return dp[i][kt][st][md];
    }
    int ma = 9;
    if (kt==0) ma = a[i];
    dp[i][kt][st][md] = 0;
    FOR(dig,0,ma)
        dp[i][kt][st][md] = (dp[i][kt][st][md] + call(i+1,dig==ma ? kt:1,st | (dig>0), (md+dig)%d, len)) % MOD;
    return dp[i][kt][st][md];
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
    string s;
    cin >> s >> d;
    memset(dp,-1,sizeof(dp));
    FOr(i,0,s.size()) 
        a[i] = s[i] - '0';
    cout << call(0,0,0,0,s.size());
}