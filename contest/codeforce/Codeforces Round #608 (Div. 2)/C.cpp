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
const long long MX = (long long)(1e9);
const long long MMX = (long long)(1e18);
typedef long long LL;
int n,x,y,hh[200005][2],p,ans,a1,a2,c1,c2,k;
int main()
{
    inI3(n,x,y);
    for(int i=1;i<=n;i++)
    {
        inI2(hh[i][0],hh[i][1]);
    }
    c1=x+1,c2=y,k=0;
    if(x<MX)
    for(int i=1;i<=n;i++)
    {
        if(hh[i][0]>=c1)k++;
    }
    if(ans<k)
    {
        ans=k;
        a1=c1;
        a2=c2;
    }
    c1=x-1,c2=y,k=0;
    if(x>0)
    for(int i=1;i<=n;i++)
    {
        if(hh[i][0]<=c1)k++;
    }
    if(ans<k)
    {
        ans=k;
        a1=c1;
        a2=c2;
    }
    c1=x,c2=y+1,k=0;
    if(y<MX)
    for(int i=1;i<=n;i++)
    {
        if(hh[i][1]>=c2)k++;
    }
    if(ans<k)
    {
        ans=k;
        a1=c1;
        a2=c2;
    }
    c1=x,c2=y-1,k=0;
    if(y>0)
    for(int i=1;i<=n;i++)
    {
        if(hh[i][1]<=c2)k++;
    }
    if(ans<k)
    {
        ans=k;
        a1=c1;
        a2=c2;
    }
    printf("%d\n%d %d",ans,a1,a2);
}
