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
int n,a,ans,cc;
bool cor;
char c[1000005];
int main()
{
    scanf("%d",&n);
    scanf("%s",c+1);
    for(int i=1;i<=n;i++)
    {
        cc++;
        if(c[i]=='(')a++;
        else a--;
        if(a<0)cor=true;
        if(a==0&&cor)cor=false,ans+=cc,cc=0;
        if(a==0&&(!cor))cc=0;
    }
    if(a!=0)printf("-1");
    else printf("%d",ans);
}
