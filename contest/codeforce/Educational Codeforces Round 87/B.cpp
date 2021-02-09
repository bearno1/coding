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
char c[200005];
int t,ans,co[1000],cur,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans=imx;
        cur=0;
        scanf("%s",c+1);
        n=strlen(c+1);
        c[0]='0';
        co[1]=0,co[2]=0,co[3]=0,co[0]=0;
        for(int i=1;i<=n;i++)
        {
            co[c[i-1]-'0']--;
            if(cur>n)break;
            while(co[1]<=0||co[2]<=0||co[3]<=0)
            {
                cur++;
                if(cur>n)break;
                co[c[cur]-'0']++;
            }
            if(co[1]>0&&co[2]>0&&co[3]>0)ans=min(ans,cur-i+1);
        }
        if(ans==imx)printf("0\n");
        else printf("%d\n",ans);
    }
}
