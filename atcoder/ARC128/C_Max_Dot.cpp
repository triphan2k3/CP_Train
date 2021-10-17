#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
#define int long long
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int n,m,s;
int a[N];
ld call(int l, int r, int s) {
    ld len = r-l+1;
    ld sum = a[r]-a[l-1];
    ld each = min((ld)m,s/len);
    return sum*each;
}
main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    cin >> n >> m >> s;
    FOR(i,1,n) {
        cin >> a[i];
        a[i]+=a[i-1];
    }
    ld ans = 0;
    for(int l=1;l<=n;l++) {
        if (m*(n-l+1) < s) break;
        ans = max(ans,call(l,n,s));
        for(int r=l+1;r<=n;r++) {
            int cost = min(s,m*(n-r+1));
            ans = max(ans,call(r,n,cost)+call(l,r-1,s-cost));
        }
    }
    cout << setprecision(6) << fixed << ans;
}