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
int t,n,q,x,c,num[100005],aa,bb;
LL a,b;
char d[5];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&x),num[x]++;
    for(int i=1;i<=100000;i++)
    {
        if(num[i]>=4)b+=(num[i])/4;
        if(num[i]>=2)a+=(num[i]%4)/2;
        //if(num[i]!=0)printf("%d [%d %d]{%d %d}",num[i],(num[i])/4,(num[i]%4)/2,b,a);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%s",d+1);
        scanf("%d",&x);
        if(num[x]>=4)b-=(num[x])/4;
        if(num[x]>=2)a-=(num[x]%4)/2;
        if(d[1]=='+')
        {
            num[x]++;
        }
        else
        {
            num[x]--;
        }
        if(num[x]>=4)b+=(num[x])/4;
        if(num[x]>=2)a+=(num[x]%4)/2;
        //printf("[%lld %lld %lld]\n",a,b,(a+((b-1)*2)));
        if(b>=1&&((a+((b-1)*2))>=2))printf("YES\n");
        else printf("NO\n");
    }
}
