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

const int N=1e3+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int m,n;
int a[N][N],c[N][N];
int X[8]={1,-1,0, 0,1, 1,-1,-1};
int Y[8]={0, 0,1,-1,1,-1, 1,-1};

bool notvalid(int u,int v) {
    return u==0 || v==0 || u==m+1 || v==n+1;
}
int proces(int l,int r) {
    FOR(i,1,m)
        FOR(j,1,n)
            c[i][j] = 0;
    int ret = 0;
    FOR(i,1,m) FOR(j,1,n) if (a[i][j] && !c[i][j]) {
        ret++;
        queue<ii> q;
        q.push({i,j});
        c[i][j]=1;
        while(q.size()) {
            int u=q.front().F;
            int v=q.front().S;
            q.pop();
            FOR(i,l,r) {
                int nu = u+X[i];
                int nv = v+Y[i];
                if (notvalid(nu,nv)) continue;
                if (!a[nu][nv] || c[nu][nv]) continue;
                c[nu][nv]=1;
                q.push({nu,nv});
            }
        }
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
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        FOR(i,1,m) {
            string s;
            cin >> s;
            FOR(j,1,n)
                a[i][j] = s[j-1]-'0';
        }
        cout << proces(0,3) << " " << proces(4,7) << " " << proces(0,7) << "\n";
    }
}