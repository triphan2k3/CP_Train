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

const int N=3e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int f[N];
int a[22][22];
int n;

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    //f[mask] so cach ghep cac nguoi dan ong trong mask voi cac nguoi phu nu tu 1 den numbitofmask
    cin >> n;
    FOR(i,1,n) FOR(j,1,n) cin >> a[i][j];
    f[0] = 1;
    FOr(mask,1,1<<n) {
        int num = __builtin_popcount(mask);
        FOR(j,0,n-1)
            if ((mask & (1<<j)) && (a[j+1][num]))
                f[mask] = (f[mask] + f[mask ^ (1<<j)]) % MOD;
    }
    cout << f[(1<<n) - 1];
}