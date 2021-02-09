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
int n,t,c1,c2,h,a,b,c,d,ans,ss;
char sr[1005];
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%d %d %d %d",&n,&c1,&c2,&h);
        scanf("%s",sr+1);
        a=0,b=0;
        for(int i=1;i<=n;i++)
        {
            if(sr[i]=='0')a++;
            else b++;
        }
        ans=(a*c1)+(b*c2);
        c=a,d=b,ss=0;
        for(c=a;c>=0;c--,d++,ss+=h)
        {
            ans=min(ans,(c*c1)+(d*c2)+ss);
        }
        c=a,d=b,ss=0;
        for(d=b;d>=0;d--,c++,ss+=h)
        {
            ans=min(ans,(c*c1)+(d*c2)+ss);
        }
        printf("%d\n",ans);
    }
}
