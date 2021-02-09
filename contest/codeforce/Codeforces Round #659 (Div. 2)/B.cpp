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
bool p;
int t,n,k,l,val[300005],st,di;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%d %d %d",&n,&k,&l);
        for(int i=1;i<=n;i++)scanf("%d",&val[i]),val[i]=l-val[i];
        di=-1;
        st=k;
        p=true;
        for(int i=1;i<=n;i++)
        {
            if(val[i]<0||st<0)p=false;
            if(di==-1)
            {
                st=min(st-1,val[i]);
            }
            else
            {
                st++;
                if(st>val[i])p=false;
            }
            if(st==0)di=1;
            if(val[i]>=k)st=k,di=-1;
            //printf("%d ",st);
        }
        if(p)printf("YES\n");
        else printf("NO\n");
    }
}
