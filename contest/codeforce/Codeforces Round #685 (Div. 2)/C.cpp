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
int t,n,ans,k,co[35][2];
char c[2][1000006];
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        bool ans=true;
        scanf("%d %d",&n,&k);
        for(int i=0;i<35;i++)co[i][0]=0,co[i][1]=0;
        scanf("%s",c[0]+1);
        scanf("%s",c[1]+1);
        for(int i=1;i<=n;i++)co[c[0][i]-'a'][0]++;
        for(int i=1;i<=n;i++)co[c[1][i]-'a'][1]++;
        for(int i=0;i<30;i++)
        {
            if(co[i][0]==co[i][1])continue;
            if(co[i][0]<co[i][1])ans=false;
            co[i+1][0]+=((co[i][0]-co[i][1])/k)*k;
            co[i][0]-=((co[i][0]-co[i][1])/k)*k;
            if(co[i][0]!=co[i][1])ans=false;
        }
        if(ans)printf("Yes\n");
        else printf("No\n");
    }
}
