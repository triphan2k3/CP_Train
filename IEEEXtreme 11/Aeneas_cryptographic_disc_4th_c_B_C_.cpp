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
const ld pi = 3.141592654;
ld r;
ld goc[26];
ld dist[26][26];
ld COS(ld goc) {
    return cos(goc/180*pi);
}

ld call(ld goc) {
    return sqrt(2.0*r*r*(1-COS(goc)));
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
    cin >> r;
    FOR(i,1,26) {
        char c;
        cin >> c;
        cin >> goc[c-'A'];
    }
    FOR(i,0,25)
        FOR(j,0,25) 
            dist[i][j]=call(goc[i]-goc[j]);
    string s;
    getline(cin,s);
    getline(cin,s);
    vector<int> u;
    FOr(i,0,s.size()) {
        if (s[i]<='Z' && s[i]>='A') u.pb(s[i]);
        if (s[i]<='z' && s[i]>='a') u.pb(toupper(s[i]));
    }
    ld ans = 0;
    FOr(i,1,u.size()) {
        //cout << (char)u[i] << (char)u[i-1] << " " << dist[u[i]-'A'][u[i-1]-'A'] << "\n";
        ans+=dist[u[i]-'A'][u[i-1]-'A'];
    }
    //cout << ans+r << "\n";
    if (u.size())
        ans= ans + r +0.9999999;
    cout << (int)ans;
    
}