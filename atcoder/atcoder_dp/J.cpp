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

const int N=307;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int called[N][N][N];
ld dp[N][N][N];
int n;
int cnt[4];

ld call(int i,int j,int k) {
    if (i < 0 || j < 0 || k < 0) return 0;
    if (i==0 && j==0 && k==0) return 0;
    if (called[i][j][k]) return dp[i][j][k];


    int sum = i + j + k;
    ld x = i>0 ? call(i-1,j,k)*i / sum : 0;
    ld y = j>0 ? call(i+1,j-1,k)*j / sum : 0;
    ld z = k>0 ? call(i,j+1,k-1)*k / sum : 0;
    // dp[i][j][k] = i/n*(1+dp[i-1][j][k]) + j/n*1+dp[i+1][j-1][k]) + k/n*(1+dp[i][j+1][k-1]) : EV chon 1 2 3 , +1 la do chon o luot nay
    //              +(n-i-j-k)/n*(1+dp[i][j][k])
    // nhan n cho 2 ve roi chuyen ve ta duoc
    // dp[i][j][k] = (n + i*dp[i-1][j][k] + j*dp[i+1][j-1][k] + k*dp[i][j+1][k-1])/(i+j+k);
    dp[i][j][k]= x + y + z + 1.0*n/sum;
    called[i][j][k]=1;
    return dp[i][j][k];
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
    cin >> n;
    FOR(i,1,n) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    cout << setprecision(9) << fixed << call(cnt[1],cnt[2],cnt[3]);
}