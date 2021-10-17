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
int a[N];
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
    FOR(i,1,n)
        cin >> a[i];
    a[n+1] = MOD;
    vector<int> ans(n+1,0);
    for(int i=1;i<=n;)
        if (a[i]<=a[i+1]) ++i;
        else {
            ans[i] = 1;
            while(a[i+1]>=a[i+2] && i<n) i++;
            ans[i+1] = 1;
            i+=2;
        }
    FOR(i,1,n)
        cout << ans[i] << " ";
}