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
int pre[N][26];
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
    cin >> s;
    int n = s.size();
    s = "#"+s;
    FOR(i,1,n)
        FOR(ch,'a','z')
            pre[i][ch-'a'] = s[i]==ch ? i:pre[i-1][ch-'a'];
    int t;
    cin >>t;
    while (t--) {
        string p;
        cin >> p;
        int ans = 0;
        int pos = n;
        while (p.size()) {
            int ch = p.back();
            p.pop_back();
            pos = pre[pos][ch-'a'];
            ans+=pos-->0;
            if (pos<=0) break;
        }
        cout << ans << "\n";
    }
}