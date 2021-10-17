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
    int n;
    int a[50][50];
    matrix (int x) {
        n = x;
        FOr(i,0,n) FOr(j,0,n) a[i][j] = 0;
    }
    matrix operator * (matrix b) {
        matrix c = matrix(n);
        FOr(i,0,n)
            FOr(j,0,n) 
                FOr(k,0,n)
                c.a[i][j] = (1LL*a[i][k]*b.a[k][j]+c.a[i][j]) % MOD;
        return c;
    }
    matrix operator ^ (ll n) {
        if (n == 1) return (*this);
        matrix tmp = (*this) ^ (n/2);
        tmp = tmp * tmp;
        if (n%2)
            tmp = tmp * (*this);
        return tmp;
    }
    int sum() {
        int ans = 0;
        FOr(i,0,n) FOr(j,0,n)
            ans = (ans+a[i][j]) % MOD;
        return ans;
    }
};
int n;
ll k;
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    cin >> n >> k;
    matrix a = matrix(n);
    FOr(i,0,n) FOr(j,0,n) cin >> a.a[i][j];
    a = a^k;
    cout << a.sum();
}