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

const int N=300+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int cnt[N],vowel[N];
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
    vowel['A']=vowel['O']=vowel['E']=vowel['U']=vowel['I']=1;
    FOR(q,1,t) {
        string s;
        cin >> s;
        int n=s.size();
        s=" "+s;
        int cntv = 0;
        FOR(i,'A','Z') cnt[i] = 0;
        FOR(i,1,n) {
            cnt[s[i]]++;
            cntv+=vowel[s[i]];
        }
        int cntc=n-cntv;
        int ans = 2*n;
        FOR(rem,'A','Z') {
            if (vowel[rem]) 
                ans=min(ans, cntc + 2*(cntv-cnt[rem]));
            else
                ans=min(ans, cntv + 2*(cntc-cnt[rem]));
        }
        cout << "Case #" << q << ": " << ans << "\n";
    }
}
