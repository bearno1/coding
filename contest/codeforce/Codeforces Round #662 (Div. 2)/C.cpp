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
int n,t,num[100005],mx,di,co,x;
priority_queue<int>pq;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        mx=0,di=0,co=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)num[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            num[x]++;
        }
        for(int i=1;i<=n;i++)pq.push(num[i]);
        mx=pq.top();
        pq.pop();
        mx--;
        while(!pq.empty())
        {
            x=pq.top();
            pq.pop();
            if(x>mx)
            {
                di++;
            }
            else
            {
                co+=x;
                if(co>=mx)co-=mx,di++;
            }
        }
        printf("%d\n",di);
    }
}
