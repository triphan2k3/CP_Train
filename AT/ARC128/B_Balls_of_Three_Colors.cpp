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
        vector<int> a(3),b;
        cin >> a[0] >> a[1] >> a[2];
        int ans = MOD;
        b = a;
        // b[0] rem
        int tmp = min(b[1],b[2]);
        b[1] -= tmp;
        b[2] -= tmp;
        int rem = b[1] +b[2];
        if (rem % 3 == 0)
            ans = tmp + rem;
        //b[1] rem
        b = a;
        tmp = min(b[0],b[2]);
        b[0] -= tmp;
        b[2] -= tmp;
        rem = b[0] +b[2];
        if (rem % 3 == 0)
            ans = min(ans,tmp + rem);
        //b[2] rem
        b = a;
        tmp = min(b[0],b[1]);
        b[0] -= tmp;
        b[1] -= tmp;
        rem = b[0] +b[1];
        if (rem % 3 == 0)
            ans = min(ans,tmp + rem);
        if (ans == MOD) ans = -1;
        cout << ans << "\n";

    }
}