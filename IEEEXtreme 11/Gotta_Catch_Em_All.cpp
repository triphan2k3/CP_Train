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
int a[N][N],f[N][N];
int r,c;
bool ok(int w) {
    f[0][1] = w;
    FOR(i,1,r)
        FOR(j,1,c) {
            f[i][j] = max(f[i-1][j],f[i][j-1]) + a[i][j];
            if (f[i][j]<=0) f[i][j] = -MOD;
        }
    return f[r][c]>0;
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
    cin >> r >> c;
    int L = 1, R = 1;
    FOR(i,1,c)
        f[0][i]=-MOD;
    FOR(i,1,r)
        f[i][0]=-MOD;
    FOR(i,1,r)
        FOR(j,1,c) {
            cin >> a[i][j];
            if (a[i][j]<0)
                R-=a[i][j];
        }
    int ans = R;
    while (L<=R) {
        int M = (L+R) / 2;
        if (ok(M)) 
            ans = M, R = M - 1;
        else
            L = M + 1;
    }
    cout << ans;
}