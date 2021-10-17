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

const int N=2e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
vector<int> a[N];
int r, c, res, k;
void proces() {
    vector<int> cnt(c, 0);
    FOr(i, 0, k) 
    FOr(j, 0, c) 
        if (a[i][j]) cnt[j]++;

    FOR(i,k,r) {
        int numone = 0;
        FOr(j, 0, c) 
            if (a[i][j]) cnt[j]++;
        FOr(j, 0, c) 
            if (cnt[j] >= k + 1 || (a[i][j])) numone++;
        res = min(res, i - k + numone);
    }
}

int main() {
    #ifdef TriPhan
        freopen("valet_parking_chapter_1_input.txt","r",stdin);
        freopen("valet_parking_chapter_1_output.txt","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t; cin >> t;
    FOR(q,1,t) {
        cin >> r >> c >> k;
        FOr(i,0,r) {
            string s;
            cin >> s;
            FOr(j,0,c) {
                int val = s[j] == 'X' ? 1:0;
                a[i].push_back(val);
            }
        }
        FOR(i,1,c) a[r].push_back(0);
        res = c;
        k--;
        proces();
        k = r - 1 - k;
        FOR(i,0,r/2 - 1)
            swap(a[i], a[r-1-i]);
        proces();
        FOR(i,0,r) a[i].clear();
        cout << "Case #" << q << ": " << res << "\n";   
    }
}
