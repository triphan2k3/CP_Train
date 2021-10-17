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
    int t; cin >> t;
    while (t--) {
        ll x,y;
        cin >> x >> y;
        ll tmp = sqrt(x*x+y*y);
        if (tmp*tmp == x*x +y*y) {
            cout << "1\n";
            continue;
        } 
        else if (x==y) {
            cout << "0\n";
            continue;
        }
        tmp = sqrt(abs(x*x-y*y));
        if (tmp*tmp == abs(x*x-y*y))
        cout<<"1\n";
        else
        cout << "0\n";        
    }
}