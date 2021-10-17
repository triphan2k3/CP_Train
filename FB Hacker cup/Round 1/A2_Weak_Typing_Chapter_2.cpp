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
        freopen("A2.txt","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t; cin >> t;
    FOR(q,1,t) {
        int n; cin >> n;
        string s; cin >> s;

        int hand = 0;
        FOr(i,0,n) if (s[i]!='F') {
            hand = (s[i]=='O');
            break;
        }

        ll ans = 0;
        int pre = 0;
        FOr(i,0,n) if (s[i]!='F') {
            int nexthand = (s[i]=='O');
            if (nexthand != hand) 
                ans = (ans+1LL*(pre+1)*(n-i)) % MOD;
            hand = nexthand;
            pre = i;
        }
        cout << "Case #" << q << ": " << ans << "\n";
    }
}