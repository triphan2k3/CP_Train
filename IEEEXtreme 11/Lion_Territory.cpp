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

const int N=4e3+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int s[N][N];
ii a[1000007];
int d[1000007];
int n,m,k,ans,id;
void query(int a, int b, int c, int d) {
    //cout << a << " " << b << " " << c << " " << d << "\n";
    
    s[ a ][ b ]++;
    s[ a ][d+1]--;
    s[c+1][ b ]--;
    s[c+1][d+1]++;

    
}
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    cin >> n >> m >> k;
    FOR(i,1,k) {
        int x,y;
        cin >> x >> y >> d[i];
        a[i]={x-y+2000,x+y+1000};
    }
    FOR(i,1,k) 
        query(a[i].F-d[i],a[i].S-d[i],a[i].F+d[i],a[i].S+d[i]);
    
    FOR(i,1,3000) 
        FOR(j,1,3000) 
            s[i][j]=s[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];

    
    FOR(i,1,k)
        if (s[a[i].F][a[i].S] > ans) {
            ans = s[a[i].F][a[i].S];
            id = i;
        }
    cout << id << " " << ans-1;
}