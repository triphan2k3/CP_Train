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
set<ll> preproces() {
    int cnt = 0;
    ll pro = 1;
    set<ll> ret;
    FOR(i,2,47) {
        int dem = 0;
        FOR(j,2,i-1) if (i%j==0) dem++;
        if (dem) continue;
        cnt++;
        pro*=i;
        ret.insert(pro);
    }
    return ret;
}
vector<ii> e[N];
int f[N],dp[N],d[N];
ll a[N];
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    set<ll> s=preproces();
    s.insert(1);
    int n,m;
    cin >> n >> m;
    map<ll,int> mp;

    vector<ll> v;
    FOR(i,1,n) {
        cin >> a[i];
        v.pb(a[i]);
        f[i] = distance(s.begin(),s.upper_bound(a[i]))-1;
    }
    sort(f+1,f+n+1);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        mp[v[i]]=i+1;
    FOR(i,1,m) {
        ll u,v,w;
        cin >> u >> v >> w;
        u = mp[u];
        v = mp[v];
        e[u].pb({v,w});
        e[v].pb({u,w});
        //cout << u << " "<< v << " "<< w<<"\n";
    }
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    FOR(i,2,n)
        d[i]=MOD;
    dp[1] = f[1];
    pq.push({0,1});
    while (pq.size()) {
        int u = pq.top().S;
        int du = pq.top().F;
        pq.pop();
        for(ii edge:e[u]) {
            int v = edge.F;
            int w = edge.S;
            if (du+w<d[v]) {
                d[v] = d[u]+w;
                dp[v]=dp[u]+f[v];
                pq.push({d[v],v});
            } 
            if  (du+w==d[v])
                dp[v] = max(dp[v],dp[u]+f[v]);
        }
    }
    //FOR(i,1,n) cout << dp[i] << " "; cout << "\n";
    cout << dp[n];
    
}