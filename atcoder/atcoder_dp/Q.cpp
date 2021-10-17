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
ll BIT[N];
int a[N],h[N];
int n;
ll get(int x) {
    ll ret = BIT[x];
    for(;x>0;x-=x&(-x))
        ret = max(ret,BIT[x]);
    return ret;
}

void update(int x, ll v) {
    for(;x<=n;x+=x&(-x))
        BIT[x]=max(BIT[x],v);
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
    cin >> n;
    FOR(i,1,n)
        cin >> h[i];
    FOR(i,1,n)
        cin >> a[i];
    ll ans = 0;
    FOR(i,1,n) {
        ll tmp = get(h[i]) + a[i];
        ans = max(ans,tmp);
        update(h[i],tmp);
    }
    cout << ans;
}