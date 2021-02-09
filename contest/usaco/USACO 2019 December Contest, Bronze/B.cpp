#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
#define inI(x) scanf("%d",&x)
#define inI2(x,y) scanf("%d %d",&x,&y)
#define inI3(x,y,z) scanf("%d %d %d",&x,&y,&z)
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
int n;
string s,tmp;
int main()
{
    freopen("whereami.in","r",stdin);
    freopen("whereami.out","w",stdout);
    cin >> n;
    cin >> s;
    for(int i=1;i<=n;i++)
    {
        set<string> ss;
        bool ok=true;
        for(int j=0;j<=n-i;j++)
        {
            tmp = s.substr(j,i);
            if(ss.find(tmp)!=ss.end())
                ok=false;
            ss.insert(tmp);
        }
        if(ok)
        {
            cout << i << '\n';
            return 0;
        }
    }
}
