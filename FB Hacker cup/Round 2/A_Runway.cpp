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
        freopen("runway_input.txt","r",stdin);
        freopen("runway_output.txt","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t; cin >> t;
    FOR(q,1,t) {
        int n,m;
        int ans = 0;
        cin >> n >> m;
        vector<int> free,unfree; 
        FOR(i,1,m) {
            int x; cin >> x; 
            free.pb(x);
        }
        FOR(i,1,n) {
            vector<int> line;
            unordered_map<int,int> vl;
            FOR(j,1,m) {
                int x; cin >> x;
                vl[x]++;
                line.pb(x);
                
            }
            vector<int> newfree, newunfree;
            for(int x:unfree) if (vl[x]) {
                newunfree.pb(x);
                vl[x]--;
            }
            for(int x:free) if (vl[x]) {
                newfree.pb(x);
                vl[x]--;
            }
            ans+=unfree.size() - newunfree.size();
            for(int x:line) if (vl[x]) {
                newunfree.pb(x);
                vl[x]--;
            }
            free = newfree;
            unfree = newunfree;
        }
        cout << "Case #" << q << ": " << ans << "\n";
    }
}