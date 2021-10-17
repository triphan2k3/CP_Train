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
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    string s,t;
    cin >> s >> t;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    int n = s.size();
    int m = t.size();
    s = '#' + s;
    t = '#' + t;
    FOR(i,1,n) FOR(j,1,m)
        dp[i][j]=max(max(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]+(s[i]==t[j]));
    int l = n;
    int r = m;
    
    while (l && r) {
        if (s[l] == t[r]) {
            cout << s[l];
            l--;
            r--;
            continue;
        }
        if (dp[l][r-1] == dp[l][r]) r--;
        else l--;
    }
}