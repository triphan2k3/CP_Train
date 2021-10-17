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
const int numday[2][13]={{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
const int nowyear=2020;
struct data {
    string name, shortname, longname, number, type, color, action, font, last, date, action2, bull, bear, colname;
    string fontcol[10],bgcol[10],num[40];
};
string a[10000];
data f[10000],g1[7][10000], g2[7][10000], g3[7][10000], g4[7][10000];
int it,n,T,sl[7],nh;
string nowd;
map<string,int> mp[7];

void makename(data &a, string &s) {
    it=s.find("</TD><TD>");
    a.longname=s.substr(0,it);
    s.erase(0,it+9);
    if (a.longname.find("_VN30")==-1)
        a.shortname=a.name=a.longname;
    else {
        string t=a.longname;
        a.colname=t.substr(16,7);
        t.erase(0,25);
        a.shortname=t.substr(0,t.find("("));
        a.name=t.substr(0,t.find(")")+1);
    }
}
void makeyear() {
    if (nowyear % 4)
        nh=1;
    else
        nh=0;
}
void file1() {
    //return;

    string s;
    for (int i = 1;i <= n;i++) {
        s = a[i];
        s.erase(0, 8);
        if (i==488) {
            int q=2;
        }
        makename(g1[T][i],s);
        mp[T][g1[T][i].name] = 1;
        if (s[2]!='/') {
            it=s.find("<");
            g1[T][i].type=s.substr(0,it);
            s.erase(0,it+9);
        }
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
        for (int j=1;j<=7;j++)
        while (1) {
            it=g1[T][i].num[j].find(",");
            if (it==-1) break;
            g1[T][i].num[j].replace(it,1,".");
        }
    }
}
void file2() {
    string s;
    for (int i=1;i<=n;i++) {
        s=a[i];
        s.erase(0,8);
        makename(g2[T][i],s);
        mp[T][g2[T][i].name] = 1;
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
        for (int j=1;j<=8;j++)
        while (1) {
            it=g2[T][i].num[j].find(",");
            if (it==-1) break;
            g2[T][i].num[j].replace(it,1,".");
        }
    }
}

void file3() {
    string s;
    for (int i=1;i<=n;i++) {
        s=a[i];
        s.erase(0,8);
        makename(g3[T][i],s);
        mp[T][g3[T][i].name] = 1;
        g3[T][i].date=s.substr(0,10);
        s.erase(0,19);
        for (int j=1;j<=37;j++) {
            it=s.find("<");
            g3[T][i].num[j]=s.substr(0,it);
            s.erase(0,it+9);
            while (s[0]==' ') s.erase(0,1);
        }
        for (int j=1;j<=37;j++)
        while (1) {
            it=g3[T][i].num[j].find(",");
            if (it==-1) break;
            g3[T][i].num[j].replace(it,1,".");
        }
    }
}
void file4() {
    string s;
    for (int i=1;i<=n;i++) {
        s=a[i];
        s.erase(0,8);
        makename(g4[T][i],s);
        mp[T][g4[T][i].name] = 1;
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
        for (int j=1;j<=24;j++)
        while (1) {
            it=g4[T][i].num[j].find(",");
            if (it==-1) break;
            g4[T][i].num[j].replace(it,1,".");
        }
    }
}
void in1(data a) {
    int i=0,ifon=0,ibg=0;
    if (a.date!="") {
        cout<< a.colname << " , ";
       // cout<< a.name;
    }
    else
        cout << " , ";
    cout << a.name << " , ";
    //cout << " , ";
    cout<< a.type << " , ";
    cout<< a.date << " , ";
    cout<< a.color << " , ";
    cout<< a.fontcol[++ifon] << " , ";
    cout<< a.num[++i] << " , ";
    cout<< a.fontcol[++ifon] << " , ";
    cout<< a.num[++i] << " , ";
    cout<< a.num[++i] << " , ";
    cout<< a.num[++i] << " , ";
    cout<< a.fontcol[++ifon] << " , ";
    cout<< a.num[++i] << " , ";
    cout<< a.bgcol[++ibg] << " , ";
    cout<< a.fontcol[++ifon] << " , ";
    cout<< a.bgcol[++ibg] << " , ";
    cout<< a.fontcol[++ifon] << " , ";
    cout<< a.num[++i] << " , ";
    cout<< a.bgcol[++ibg] << " , ";
    cout<< a.fontcol[++ifon] << " , ";
    cout<< a.num[++i] << " , ";

}
void in2(data a) {
    int ifon=0,ibg=0,i=0;
    //cout<< a.name << "\n";
    //cout<< a.date << "\n";
    cout<< a.fontcol[++ifon]<<" , ";
    cout<< a.num[++i]<<" , ";
    cout<< a.font<<" , ";
    cout<< a.num[++i]<<" , ";
    cout<< a.bgcol[++ibg]<<" , ";
    cout<< a.fontcol[++ifon]<<" , ";
    cout<< a.num[++i]<<" , ";
    cout<< a.num[++i]<<" , ";
    cout<< a.bgcol[++ibg]<<" , ";
    cout<< a.fontcol[++ifon]<<" , ";
    cout<< a.num[++i]<<" , ";
    cout<< a.num[++i]<<" , ";
    cout<< a.bgcol[++ibg]<<" , ";
    cout<< a.fontcol[++ifon]<<" , ";
    cout<< a.num[++i]<<" , ";
    cout<< a.num[++i]<<" , ";
    cout<< a.bgcol[++ibg]<<" , ";
    cout<< a.fontcol[++ifon]<<" , ";
    cout<< a.last << " , ";
}
void in3(data a) {
    //cout<< a.name << "\n";
    //cout<< a.date << "\n";
    for (int i=1;i<=37;i++)
        cout << a.num[i] << " , ";

}
void in4(data a) {
    //cout<< a.name << "\n";
    //cout<< a.date << "\n";
    cout<< a.num[1]<<" , ";
    cout<< a.num[2]<<" , ";
    cout<< a.bull << " , ";
    cout<< a.bear << " , ";
    cout<< a.action << " , ";
    cout<< a.number << " , ";
    for (int i=0;i<a.action2.size();i++)
        if (a.action2[i]!=',')
        cout<< a.action2[i];
    cout<< " , ";
    for (int i=3;i<=24;i++)
        cout << a.num[i] << " , ";
    cout<<" , ";
}
void inra(int i,int j) {
    in1(g1[i][j]);
    in2(g2[i][j]);
    in3(g3[i][j]);
    in4(g4[i][j]);
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
        return;
    }
    //return;
    if (s.find("FONT COLOR")!=-1) {
        file2();
        return;
    }
    if (s.find("(")==-1) {
        file3();
        return;
    }

    file4();
}

string prev_day(string daymonth) {
    string day=daymonth.substr(0,2);
    string month=daymonth.substr(2,daymonth.size()-2);
    int d=(day[0]-'0')*10 + day[1]-'0';
    int m=month.size()==1 ? month[0]-'0' : 10+month[1]-'0';
    int pd,pm;
    if (d==1) {
        if (m==1) {
            pm=12;
            pd=31;
        }
        else {
            pm=m-1;
            pd=numday[nh][pm];
        }
    }
    else {
        pd=d-1;
        pm=m;
    }
    day=to_string(pd);
    month=to_string(pm);
    if (day.size()==1) day="0"+day;
    return day+month;
}
void input(string st) {
    string day=nowd;
    string s;
    T=0;
    for (int i=0;i<6;i++) {
        n=0;
        string filename=st+day+".html";
        ifstream cin(filename);
        for (int i=1;i<=10;i++)
            getline(cin,s);
        while(getline(cin,s)) { for (auto & c:s) c=toupper(c); a[++n]=s; }
        n-=3;
        start();
        cin.close();
        day=prev_day(day);
    }
}
void cleandata() {
    string s;
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
}
int main() {
    nowd="057";
    makeyear();
    input("");
    input("i");
    input("g");
    input("p");

    cleandata();
    freopen("output.csv","w",stdout);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=T;j++) {
            cout << g1[j][i].shortname << " , ";
            cout << g2[j][i].shortname << " , ";
            cout << g3[j][i].shortname << " , ";
            cout << g4[j][i].shortname << " , ";
        }
        cout << "\n";
        for (int j=1;j<=T;j++) {
            cout << g1[j][i].longname << " , ";
            cout << g2[j][i].longname << " , ";
            cout << g3[j][i].longname << " , ";
            cout << g4[j][i].longname << " , ";
        }
        cout << "\n";
    }
    return 0;

    for (int i=1;i<=T;i++)
        for (int j=1;j<=n;j++)
            inra(i,j);

    return 0;
}
