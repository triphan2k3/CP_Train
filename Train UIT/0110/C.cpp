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

const int N=1e6+2;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int s[N],qa[N],qd[N];
int val[N];
ii a[N];
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int n,t;
    cin >> n >> t;
    vector<int> p;
    FOR(i,1,t) {
        cin >> a[i].F >> a[i].S;
        if (a[i].F>a[i].S) swap(a[i].F,a[i].S);
        p.pb(a[i].F);
        p.pb(a[i].S);
    }
    //p.pb(1);
    //p.pb(n);
    sort(p.begin(),p.end());
    p.resize(distance(p.begin(),unique(p.begin(),p.end())));
    map<int,int> m;
    for(int i=0;i<p.size();i++) {
        m[p[i]] = i+1;
        val[i+1] = p[i];
    }
    FOR(i,1,t) {
        qa[m[a[i].F]]++;
        qd[m[a[i].S]+1]++;
        //s[m[a[i].F]]++;
        //s[m[a[i].S]+1]--;
    }
    t = p.size();
    int ans = 0;
    int cnt = 0;
    val[t+1] = n+1;
    FOR(i,1,t+1) {
        int add = qa[i];
        int dec = qd[i];
        cnt = (cnt - dec + N) % 3;
        if (cnt == 0)
            ans += val[i]-val[i-1]-1;
        cnt = (cnt + add + N)%3;
        cnt %= 3;
        if (cnt==0 && i!=t+1) ans++;
        //s[i]+=s[i-1];
    }

    //int ans = val[1]-1 + (n-val[t]) + (s[1]==0 )
    //FOR(i,1,t) 
        //if (s[i]%3 == 0) ans += val[i]-val[i-1];
    cout << ans;
}