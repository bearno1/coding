#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
typedef pair<int,int> pii;
int t,n,x;
bool p,al,kk;
vector<int>v;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        v.clear();
        al=true;
        kk=false;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(x!=i)al=false,v.pb(i);
        }
        for(int i=1;i<v.size();i++)
        {
            if(v[i]-1!=v[i-1])kk=true;
        }
        if(al)printf("0\n");
        else if(kk)printf("2\n");
        else printf("1\n");
    }
}
