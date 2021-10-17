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
    int n;
    cin >> n;
    vector<int> a(n+1,0),pref(n+1,0);
    FOR(i,1,n)
        cin >> a[i];
    pref[1]=1;
    FOR(i,2,n)
        pref[i] = a[i]<a[i-1] ? pref[i-1]:i;
    cout << "\n";
    int t;
    cin >> t;
    while(t--) {
        int l,r;
        cin >> l >> r;
        int st_index = pref[r]-1;
        if (st_index<l) {
            cout << 0 << "\n";
            continue;
        }
        int len = r - st_index;
        //cout << st_index << " ";
        int ans = len+1;
        int mid = (r+pref[r])/2;
        int flag = ((a[st_index] < a[mid]) && (a[st_index] > a[mid+1]));

        if (len%2 && len>1) 
            ans-=1^flag;
        cout << ans << "\n"; 
    }

}