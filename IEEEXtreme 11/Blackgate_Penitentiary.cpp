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
    vector<int> h(n+1);
    vector<string> e[251];
    FOR(i,1,n) {
        string s;
        cin >> s >> h[i];
        e[h[i]].push_back(s);
    }
    sort(h.begin()+1,h.end());
    for(int i=1;i<=n;) {
        int l = i;
        while(i<n && h[i+1]==h[i]) i++;
        sort(e[h[i]].begin(),e[h[i]].end());
        for(string s:e[h[i]])
            cout << s << " ";
        cout << l << " " << i++ << "\n";
    }

}