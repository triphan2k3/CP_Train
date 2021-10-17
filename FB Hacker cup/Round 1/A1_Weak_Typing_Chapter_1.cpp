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
        freopen("A1.txt","r",stdin);
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
        int ans = 0;
        FOr(i,0,n) {
            if (s[i]=='O') {
                ans += 1-hand;
                hand = 1;
            } 
            if (s[i]=='X') {
                ans += hand;
                hand = 0;
            }
        }
        cout << "Case #" << q << ": " << ans << "\n";
    }
}