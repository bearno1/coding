#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define all(x) (x).begin()s,(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define IMX INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
int t,n,r,x,las,pp[100005];
bitset<100005>uu;
bool p;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        p=true;
        r=1;
        las=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            uu[i]=false;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(x<las)p=false;
            if(x<i)p=false;
            las=x;
            if(!uu[x])pp[i]=x,uu[x]=true;
            else
            {
                while(uu[r])r++;
                pp[i]=r;
                uu[r]=true;
            }
        }
        if(p)
        {
            for(int i=1;i<=n;i++)printf("%d ",pp[i]);
            printf("\n");
        }
        else printf("-1\n");
    }
}
