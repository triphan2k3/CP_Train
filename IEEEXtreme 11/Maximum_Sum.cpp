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
    int t;cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        FOR(i,1,n)
            cin >> a[i-1];
        if (n==1) {
            cout << a[0] << "\n" << a[0] << "\n";
            continue;
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        vector<int> l,r;
        while(a.back()==0) {
            l.pb(0);
            a.pop_back();
            // co bang 0 thi cho vao dau het
        }
        int flag = 0;
        while (a.size()) {
            int num = a.back();
            int cnt = 1;
            a.pop_back();
            while (a.size() && a.back()==num) 
                a.pop_back(),cnt++;
            // dem so luong a bang num
            if (flag) {
                r.pb(num);
                if (cnt>1)
                    l.pb(num);
                else flag=0;
            }
            else {
                l.pb(num);
                if (cnt>1)
                    r.pb(num);
                else
                    flag=1;
            }
            if (cnt>1) flag = 0;
            FOR(i,3,cnt)
                l.pb(num);
        }
        reverse(r.begin(),r.end());
        for(int x:r)
            l.pb(x);
        ll ans = 0;
        FOr(i,1,l.size())
            ans+=1LL*l[i]*l[i-1];
        cout << ans << "\n";
        for(int x:l)
            cout << x << " ";
        cout << "\n";
    }
}