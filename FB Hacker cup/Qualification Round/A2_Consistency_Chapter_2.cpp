#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define sz(x) ((int) (x).size())
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

const int N=300+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int c[N][N];
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    FOR(q,1,t) {
        string s;
        int n;
        cin >> s;
        n=s.size();
        s=" " + s;
        FOR(i,'A','Z') FOR(j,'A','Z')
            c[i][j]=(i==j) ? 0 : 26;
    
        int m;
        cin >> m;
        FOR(i,1,m) {
            string s;
            cin >> s;
            c[s[0]][s[1]]=1;
        }
        FOR(k,'A','Z')
        FOR(i,'A','Z')
        FOR(j,'A','Z')
            c[i][j]=min(c[i][k]+c[k][j],c[i][j]);
        int ans=MOD;
        FOR(rem,'A','Z') {
            int res=0;
            FOR(i,1,n)
                if (c[s[i]][rem]==26) {
                    res=MOD;
                    break;
                } else
                res += c[s[i]][rem];
            ans=min(ans,res);
        }
        if (ans==MOD) ans=-1;
        cout << "Case #" << q << ": " << ans << "\n";
    }
}
