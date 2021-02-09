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
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
int n,num[300005];
LL ss,mx[300005],mn[300005],ans;
priority_queue<int>pq;
int main()
{
    ans=-MMX;
    scanf("%d",&n);
    for(int i=1;i<=3*n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(int i=1;i<=n;i++)
    {
        pq.push(-num[i]);
        ss+=num[i];
        mx[i]=ss;
    }
    for(int i=n+1;i<=3*n;i++)
    {
        if(-pq.top()<num[i])
        {
            ss+=pq.top();
            pq.pop();
            ss+=num[i];
            pq.push(-num[i]);
        }
        mx[i]=ss;
    }
    while(!pq.empty())pq.pop();
    ss=0;
    for(int i=n*3;i>n*2;i--)
    {
        pq.push(num[i]);
        ss-=num[i];
        mn[i]=ss;
    }
    for(int i=(n*2);i>0;i--)
    {
        if(pq.top()>num[i])
        {
            ss+=pq.top();
            pq.pop();
            ss-=num[i];
            pq.push(num[i]);
        }
        mn[i]=ss;
    }
    for(int i=n;i<=n*2;i++)
    {
        //printf("%d %lld %lld\n",i,mx[i],mn[i+1]);
        ans=max(ans,mx[i]+mn[i+1]);
    }
    printf("%lld",ans);
}
