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
        freopen("B.txt","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t; cin >> t;
    FOR(q,1,t) {
        int n,m,a,b;
        cin >> n >> m >> a >> b;
        if ((a < (m+n-1)) || (b < (m+n-1))) {
            cout << "Case #" << q << ": Impossible\n";
            continue; 
        }
        cout << "Case #" << q << ": Possible\n";
        a-=m+n-1;
        b-=m+n-1;
        FOR(i,1,n) 
            FOR(j,1,m) {
            if (i==n && j==1) 
                cout << 1+b << " ";
            else if (i==n && j==m) 
                cout << 1+a << " ";
            else cout << "1 ";
            if (j==m) cout << "\n";           
        }

    }
}