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
int cnt[N],p[N];

ll mu(ll a,ll b,int m) {
    if (b==1) return a;
    ll t = mu(a,b/2,m);
    t = t*t % m;
    if (b%2)
        t = t*a % m;
    return t;
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
    FOR(i,2,1000)
        if (p[i]==0)
            for(int j = i*i;j<=1000000;j+=i)
                p[j] = i;
    FOR(i,2,1000000)
        if (p[i]==0) p[i] = i;

    int t;
    cin >> t;
    while(t--) {
        int a,b,c;
        cin >> a >> b >> c;
        FOR(i,1,b) cnt[i] = 0;
        FOR(i,2,b) 
            for(int x=i;x>1;x/=p[x])
                cnt[p[x]]=cnt[p[x]] + 1 - (i<=c) - (i<=(b-c));
        ll ans = 1;
        FOR(i,2,b)
            if (cnt[i]) 
                ans = ans*mu(i,cnt[i],MOD-1) % (MOD-1);
        
        cout << mu(a,ans,MOD) << "\n";
    }
}