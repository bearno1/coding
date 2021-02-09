#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
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
int t,n,co1[25],co2[25],mx,ans,k;
char c1[100005],c2[100005],pos;
bool p;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        p=true;
        ans=0;
        scanf("%d",&n);
        scanf("%s",c1+1);
        scanf("%s",c2+1);
        for(int i=1;i<=n;i++)
        {
            if(c1[i]>c2[i])p=false;
        }
        for(int i='t';i>='b';i--)
        {
            k=0;
            pos='a';
            for(int j=1;j<=n;j++)
            {
                if(c2[j]==i&&c1[j]<i)
                {
                    k++;
                    pos=max(pos,c1[j]);
                }
            }
            if(k==0)continue;
            ans++;
            for(int j=1;j<=n;j++)
            {
                if(c2[j]==i&&c1[j]<i)
                {
                    c2[j]=pos;
                }
            }
        }
        if(!p)printf("-1\n");
        else printf("%d\n",ans);
    }
}
