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
const int sz = 25*25;
int a[30][30];
int x[8] = {0, 0,1,1, 1,-1,-1,-1};
int y[8] = {1,-1,0,1,-1, 0, 1,-1};
int m,n,c;

int cnt(int i,int j) {
    int ret = 0;
    FOr(id,0,8) {
        int ni = (i+x[id]+m)%m;
        int nj = (j+y[id]+n)%n;
        ret+=a[ni][nj];
    }
    return ret;
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
    cin >> m >> n >> c;
    FOR(i,0,m-1) {
        string s;
        cin >> s;
        FOR(j,0,n-1)
            a[i][j] = s[j]=='*';
    }
    unordered_map<bitset<sz>,int> mp;
    FOR(step,1,c) {
        vector<ii> a1,a0;
        FOr(i,0,m) FOr(j,0,n) {
            int x = cnt(i,j);
            if (x<=1 || x>=4) a0.pb({i,j});
            else
                if (x==3 || a[i][j]==1) a1.pb({i,j});
                    else a0.pb({i,j});
        }
        for(ii x:a0)
            a[x.F][x.S] = 0;
        bitset<sz> bs;
        for(ii x:a1)
            a[x.F][x.S] = 1,bs.set(x.F*n+x.S);
        if (mp[bs]) {
            int nummove = step-mp[bs];
            while (step+nummove <= c)
                step+=nummove;
        } else mp[bs] = 1;
    }
    FOr(i,0,m) {
        FOr(j,0,n)
            cout << (a[i][j] ? '*':'-');
        cout << "\n";
    }
}