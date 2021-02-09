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
char a[100005],b[100005];
int la,lb,k,pl,x;
vector<int>ans;
int main()
{
    scanf("%s",a+1);
    scanf("%s",b+1);
    la=strlen(a+1);
    lb=strlen(b+1);
    for(int i=0;i<100005;i++)
    {
        if(a[i]==0)a[i]='0';
        if(b[i]==0)b[i]='0';
    }
    k=max(la,lb);
    for(int i=la;i>0;i--)
    {
        a[k-la+i]=a[i];
        if(k!=la)a[i]='0';
    }
    for(int i=lb;i>0;i--)
    {
        b[k-lb+i]=b[i];
        if(k!=lb)b[i]='0';
    }
    for(int i=k;i>0;i--)
    {
        //printf("{%d %d}\n",a[i]-'0',b[i]-'0');
        x=(a[i]-'0')+(b[i]-'0');
        x+=pl;
        if(x>=10)pl=1;
        else pl=0;
        ans.pb(x%10);
    }
    if(pl==1)ans.pb(1);
    for(int i=ans.size()-1;i>-1;i--)
    {
        printf("%d",ans[i]);
    }
}
