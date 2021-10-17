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
ll dp[N];
int l[N],r[N],w[N];

void update(int i,int l,int r,int L,int R,int w) {
    if (L<=l && R>=r) {
        it[i]+=w;
        return;
    }
    int m = (l+r)>>1;
    update(i*2,l,m,L,R,w);
    update(i*2+1,m+1,r,L,R,w);
}

ll get(int i,int l,int r,int id) {

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
    int n,m;
    cin >> n >> m;
    FOR(i,1,m) {
        cin >> l[i] >> r[i] >> w[i];
        q[l[i]].pb({1,i});
        q[r[i]].pb({2,i});
    }
    FOR(i,1,n) {
        sort(q[i].begin(),q[i].end());
        q[i].pb({0,0});
    }
    ll cnt = 0;
    ll ans = 0;
    FOR(i,1,n) {
        int id = 0;
        for(;q[i][id].F==1;id++) {
            int pos = q[i][id].S;
            update(1,1,n,l[pos],r[pos],-w[pos]);
            cnt += w[pos];
        }
        dp[i]=cnt;
        dp[i]=max(cnt,get(1,1,n,i-1)+cnt);
        update(1,1,n,i,i,dp[i]);
        for(;q[i][id].F==2;id++) {
            int pos = q[i][id].S;
            update(1,1,n,l[pos],r[pos],w[pos]);
            cnt -= w[pos];
        }
        ans = max(ans,dp[i]);
    }
    cout << ans;
}