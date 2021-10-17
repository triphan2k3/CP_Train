#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
struct data {
    string name, number, type, color, action, font, last, date, action2, bull, bear;
    string fontcol[10],bgcol[10],num[40];
};
string a[10000];
data f[10000],g1[7][10000], g2[7][10000], g3[7][10000], g4[7][10000];
int it,n,T,sl[7];
map<string,int> mp[7];

void file1() {
    //return;
    string s;
    for (int i = 1;i <= n;i++) {
        s = a[i];
        s.erase(0, 8);
        it = s.find("<");
        g1[T][i].name = s.substr(0, it);
        mp[T][g1[T][i].name] = 1;
        if (g1[T][i].name=="A32") {
            int q=1;
            q++;
        }
        s.erase(0, it + 9);

        it = s.find(" ");
        g1[T][i].date = s.substr(it - 10, 10);
        s.erase(0, it + 1);
        it = s.find("<");
        g1[T][i].color = s.substr(0, it);
        s.erase(0, it + 9);
        for (int j = 1;j <= 6;j++) {
            it = s.find("<FONT COLOR=");
            g1[T][i].fontcol[j] = s.substr(it + 13, 7);
            s.erase(it, 22);
        }
        for (int j = 1;j <= 3;j++) {
            it = s.find("<TD BGCOLOR=");
            g1[T][i].bgcol[j] = s.substr(it + 13, 7);
            s.erase(it, 22);
        }
        for (int j = 1;j <= 2;j++) {
            it = s.find("<");
            g1[T][i].num[j] = s.substr(0, it);
            s.erase(0, it + 16);
        }
        for (int j = 3;j <= 5;j++) {
            it = s.find("<");
            g1[T][i].num[j] = s.substr(0, it);
            s.erase(0, it + 9);
        }
        it = s.find("</FONT></TD><TD>");
        s.erase(0, it + 16);
        for (int j = 6;j <= 7;j++) {
            it = s.find("<");
            g1[T][i].num[j] = s.substr(0, it);
            s.erase(0, it + 5);
        }
    }
}
void file2() {
    string s;
    for (int i=1;i<=n;i++) {
        s=a[i];
        s.erase(0,8);
        it=s.find("<");
        g2[T][i].name=s.substr(0,it);
        mp[T][g2[T][i].name] = 1;
        s.erase(0,it+9);
        g2[T][i].date=s.substr(0,10);
        s.erase(0,19);
        for (int j=1;j<=5;j++) {
            it=s.find("<FONT COLOR=");
            g2[T][i].fontcol[j]=s.substr(it+13,7);
            s.erase(it,22);
        }
        for (int j=1;j<=4;j++) {
            it=s.find("<TD BGCOLOR=");
            g2[T][i].bgcol[j]=s.substr(it+13,7);
            s.erase(it,22);
        }
        it=s.find("<");
        g2[T][i].num[1]=s.substr(0,it);
        s.erase(0,it+16);

        it=s.find("<");
        g2[T][i].font=s.substr(0,it);
        s.erase(0,it+9);

        int add[2]={5,16};
        for (int j=2;j<=8;j++) {
            it=s.find("<");
            g2[T][i].num[j]=s.substr(0,it);
            s.erase(0,it+add[j%2]);
        }

        g2[T][i].last=s.substr(0,s.size()-17);
    }
}

void file3() {
    string s;
    for (int i=1;i<=n;i++) {
        s=a[i];
        s.erase(0,8);
        it=s.find("<");
        g3[T][i].name=s.substr(0,it);
        mp[T][g3[T][i].name] = 1;
        s.erase(0,it+9);
        g3[T][i].date=s.substr(0,10);
        s.erase(0,19);
        for (int j=1;j<=37;j++) {
            it=s.find("<");
            g3[T][i].num[j]=s.substr(0,it);
            s.erase(0,it+9);
            while (s[0]==' ') s.erase(0,1);
        }
    }
}
void file4() {
    string s;
    for (int i=1;i<=n;i++) {
        s=a[i];
        s.erase(0,8);
        it=s.find("<");
        g4[T][i].name=s.substr(0,it);
        mp[T][g4[T][i].name] = 1;
        s.erase(0,it+9);
        g4[T][i].date=s.substr(0,10);
        s.erase(0,19);

        it=s.find("<");
        g4[T][i].num[1]=s.substr(0,it);
        s.erase(0,it+9);

        it=s.find("<");
        g4[T][i].num[2]=s.substr(0,it);
        s.erase(0,it+9);

        it=s.find("<");
        g4[T][i].bull=s.substr(0,it);
        s.erase(0,it+9);

        it=s.find("<");
        g4[T][i].bear=s.substr(0,it);
        s.erase(0,it+9);


        it=s.find("(");
        g4[T][i].action=s.substr(0,it);
        s.erase(0,it+1);

        it=s.find(")");
        g4[T][i].number=s.substr(0,it);
        s.erase(0,it+10);

        it=s.find("<");
        g4[T][i].action2=s.substr(0,it);
        s.erase(0,it+9);

        for (int j=3;j<=24;j++) {
            it=s.find("<");
            g4[T][i].num[j]=s.substr(0,it);
            s.erase(0,it+9);
        }
    }
}
void in1(int u) {
    int i = 0, ifon = 0, ibg = 0;
    for (int v = 1;v <= T;v++)
        cout << g1[v][u].name << " , ";
    cout << "\n";
    //return;
    //cout<< a.type << "\n";
    for (int v = 1;v <= T;v++)
        cout << g1[v][u].date << " , ";
    cout << "\n";

    for (int v = 1;v <= T;v++)
        cout << g1[v][u].color << " , ";
    cout << "\n";

    ++ifon;
    for (int v = 1;v <= T;v++)
        cout << g1[v][u].fontcol[ifon] << " , ";
    cout << "\n";

    ++i;
    for (int v = 1;v <= T;v++)
        cout << g1[v][u].num[i] << " , ";
    cout << "\n";

    ++ifon;
    for (int v = 1;v <= T;v++)
        cout << g1[v][u].fontcol[ifon] << " , ";
    cout << "\n";

    for (int z = 1;z <= 3;z++) {
        ++i;
        for (int v = 1;v <= T;v++)
            cout << g1[v][u].num[i] << " , ";
        cout << "\n";
    }

    ++ifon;
    for (int v = 1;v <= T;v++)
        cout << g1[v][u].fontcol[ifon] << " , ";
    cout << "\n";

    ++i;
    for (int v = 1;v <= T;v++)
        cout << g1[v][u].num[i] << " , ";
    cout << "\n";

    for (int z = 1;z <= 2;z++) {
        ++ibg;
        for (int v = 1;v <= T;v++)
            cout << g1[v][u].bgcol[ibg] << " , ";
        cout << "\n";
        ++ifon;
        for (int v = 1;v <= T;v++)
            cout << g1[v][u].fontcol[ifon] << " , ";
        cout << "\n";
    }

    ++i;
    for (int v = 1;v <= T;v++)
        cout << g1[v][u].num[i] << " , ";
    cout << "\n";

    ++ibg;
    for (int v = 1;v <= T;v++)
        cout << g1[v][u].bgcol[ibg] << " , ";
    cout << "\n";

    ++ifon;
    for (int v = 1;v <= T;v++)
        cout << g1[v][u].fontcol[ifon] << " , ";
    cout << "\n";

    ++i;
    for (int v = 1;v <= T;v++)
        cout << g1[v][u].num[i] << " , ";
    cout << "\n";
}
void in2(int u) {
    int ifon=0,ibg=0,i=0;
    for (int v=1;v<=T;v++)
    cout<< g2[v][u].name << " , ";
    cout<<"\n";
    //cout<< a.date << "\n";
    for (int z = 1;z <= 2;z++) {
        ++ifon;
        for (int v = 1;v <= T;v++)
            cout << g2[v][u].fontcol[ifon] << " , ";
        cout << "\n";
        ++i;
        for (int v = 1;v <= T;v++)
            cout << g2[v][u].num[i] << " , ";
        cout << "\n";
    }
    for (int z = 1;z <= 3;z++) {
        ++ibg;
        for (int v = 1;v <= T;v++)
            cout << g2[v][u].bgcol[ibg] << " , ";
        cout << "\n";
        ++ifon;
        for (int v = 1;v <= T;v++)
            cout << g2[v][u].fontcol[ifon] << " , ";
        cout << "\n";
        for (int p = 1;p <= 2;p++) {
            ++i;
            for (int v = 1;v <= T;v++)
                cout << g2[v][u].num[i] << " , ";
            cout << "\n";
        }
    }
    ++ibg;
    for (int v = 1;v <= T;v++)
        cout << g2[v][u].bgcol[ibg] << " , ";
    cout << "\n";
    for (int v = 1;v <= T;v++)
        cout << g2[v][u].fontcol[ifon] << " , ";
    cout << "\n";
    //cout<< a.last << "\n\n";
}
void in3(int u) {
    for (int v=1;v<=T;v++)
    cout<< g3[v][u].name << " , ";
    cout<<"\n";
    //cout<< a.date << "\n";

    for (int i = 1;i <= 37;i++) {
        for (int v = 1;v <= T;v++)
            cout << g3[v][u].num[i] << " , ";
        cout << "\n";
    }
}
void in4(int u) {
    for (int v=1;v<=T;v++)
    cout<< g4[v][u].name << " , ";
    cout<<"\n";
    //cout<<a.date << "\n";
    for (int z = 1;z <= 2;z++) {
        for (int v=1;v<=T;v++)
        cout << g4[v][u].num[z] << " , ";
        cout << "\n";
    }
    for (int v = 1;v <= T;v++)
        cout << g4[v][u].bull << " , ";
    cout << "\n";
    for (int v = 1;v <= T;v++)
        cout << g4[v][u].bear << " , ";
    cout << "\n";
    for (int v = 1;v <= T;v++)
        cout << g4[v][u].action << " , ";
    cout << "\n";
    for (int v = 1;v <= T;v++)
        cout << g4[v][u].number << " , ";
    cout << "\n";
    for (int v = 1;v <= T;v++)
        cout << g4[v][u].action2 << " , ";
    cout << "\n";
    for (int i = 3;i <= 24;i++) {
        for (int v = 1;v <= T;v++)
            cout << g4[v][u].num[i] << " , ";
        cout << "\n";
    }
}
void inra(int i) {
    in1(i);
    in2(i);
    in3(i);
    in4(i);
    cout<<"\n";
}
bool cmp(data a,data b) {
    return a.name < b.name;
}
void start() {
    string s;
    s=a[1];
    ++T;
    sl[T]=max(sl[T],n);
    if (s.find("RED")!=-1 || s.find("YELLOW")!=-1 || s.find("GREEN")!=-1) {
        file1();
        //sort(g1[T]+1,g1[T]+n+1,cmp);
        return;
    }
    if (s.find("FONT COLOR")!=-1) {
        file2();
        //sort(g2[T]+1,g2[T]+n+1,cmp);
        return;
    }
    if (s.find("(")==-1) {
        file3();
        //sort(g3[T]+1,g3[T]+n+1,cmp);
        return;
    }

    file4();
    //sort(g4[T]+1,g4[T]+n+1,cmp);
    /*
    if (s[2]!='/') {
        file1();
    }
    else {
        if (s.find("<FONT color=")!=-1) file2();
        else
        if (s.find("</TD><TD></TD></TR></TD></TR>")!=-1) file3();
        else file4();
    } */
}

int main() {

    string s;
    n=0;
    ifstream f1("FILE1_1.TXT");
    while(getline(f1,s)) { for (auto & c:s) c=toupper(c); a[++n]=s; }
    start();
    f1.close();

    n=0;
    ifstream f2("FILE1_2.TXT");
    while(getline(f2,s)) { for (auto & c:s) c=toupper(c); a[++n]=s; }
    start();
    f2.close();

    T=0;
    n=0;
    ifstream f3("FILE2_1.TXT");
    while(getline(f3,s)) { for (auto & c:s) c=toupper(c); a[++n]=s; }
    start();
    f3.close();

    n=0;
    ifstream f4("FILE2_2.TXT");
    while(getline(f4,s)) { for (auto & c:s) c=toupper(c); a[++n]=s; }
    start();
    f4.close();

    T=0;
    n=0;
    ifstream f5("FILE3_1.TXT");
    while(getline(f5,s)) { for (auto & c:s) c=toupper(c); a[++n]=s; }
    start();
    f5.close();

    n=0;
    ifstream f6("FILE3_2.TXT");
    while(getline(f6,s)) { for (auto & c:s) c=toupper(c); a[++n]=s; }
    start();
    f6.close();

    T=0;
    n=0;
    ifstream f7("FILE4_1.TXT");
    while(getline(f7,s)) { for (auto & c:s) c=toupper(c); a[++n]=s; }
    start();
    f7.close();

    n=0;
    ifstream f8("FILE4_2.TXT");
    while(getline(f8,s)) { for (auto & c:s) c=toupper(c); a[++n]=s; }
    start();
    f8.close();

    for (int i=1;i<=T;i++) {
        int last=sl[i];
        for (int j=1;j<=sl[i];j++) {
            s=g1[i][j].name;
            for (int k=1;k<=T;k++)
                if (!mp[k][s]) {
                    mp[k][s]=1;
                    ++sl[k];
                    g1[k][sl[k]].name=s;
                    g2[k][sl[k]].name=s;
                    g3[k][sl[k]].name=s;
                    g4[k][sl[k]].name=s;
            }
        }
    }
    n=mp[1].size();
    for (int i=1;i<=T;i++) {
        sort(g1[i]+1,g1[i]+n+1,cmp);
        sort(g2[i]+1,g2[i]+n+1,cmp);
        sort(g3[i]+1,g3[i]+n+1,cmp);
        sort(g4[i]+1,g4[i]+n+1,cmp);
    }
    freopen("FILE.OUT","w",stdout);
    for (int i=1;i<=n;i++)
        inra(i);
    return 0;
}
