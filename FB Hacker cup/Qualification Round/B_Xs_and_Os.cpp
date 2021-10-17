#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define sz(x) ((int) (x).size())
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

const int N=1e2+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int c[N],r[N],cc[N],cr[N];
int a[N][N];
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    FOR(q,1,t) {
        int n;
        cin >> n;
        FOR(i,1,n)
            r[i]=c[i]=cr[i]=cc[i]=0;
        FOR(i,1,n) {
            string s;
            cin >> s;
            FOR(j,1,n) {
                a[i][j]=0;
                if (s[j-1]=='X') {
                    r[i]++;
                    c[j]++;
                    a[i][j]=1;
                }
                if (s[j-1]=='O') {
                    cr[i]=1;
                    cc[j]=1;
                    a[i][j]=2;
                }
            }
        }
        vector<int> ans;
        FOR(i,1,n) {
            if (cr[i]==0) {
                ans.push_back(n-r[i]);
                if (n-r[i] == 1) {
                    FOR(j,1,n)
                        if (a[i][j]==0) {
                            cc[j]=1;
                            break;
                        }
                }
            }
            if (cc[i]==0) {
                ans.push_back(n-c[i]);
                if (n-c[i] == 1) {
                    FOR(j,1,n)
                        if (a[j][i]==0) {
                            cr[j]=1;
                            break;
                        }
                }
            }

        }
        if (ans.size()==0) {
            cout << "Case #" << q << ": Impossible\n";
            continue;
        }
        sort(ans.begin(),ans.end());
        int cnt=1;
        for (int i=1;i<ans.size();i++)
            if (ans[i]==ans[0]) ++cnt;
        cout << "Case #" << q << ": " << ans[0] << " " << cnt << "\n";
    }
}
