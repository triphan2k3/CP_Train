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
struct matrix {
    int a[2][2];
    matrix() {}
    matrix(int x,int b,int c,int d)  {
        a[0][0]=x; a[0][1]=b; a[1][0]=c; a[1][1]=d;
    }
};

matrix mul(matrix x,matrix y) {
    matrix c(0,0,0,0);
    FOR(i,0,1)
        FOR(j,0,1)
            c.a[i][j]=(x.a[i][0]*y.a[0][j]+x.a[i][1]*y.a[1][j]) % 10;
    return c;
}
matrix Pow(matrix a,int n) {
    if (n==1) return a;
    matrix t = Pow(a,n/2);
    t = mul(t,t);
    if (n%2) t = mul(t,a);
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n==1) {
            cout << "1\n";
            continue;
        }
        matrix t(1,1,1,0);
        t = Pow(t,n-1);
        int ans = t.a[0][1]*2 + t.a[1][1];
        cout << ans%10 << "\n";
    }
}