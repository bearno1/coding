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
int n,a,b,nn[206];
queue<int>q;
char c[206];
int main()
{
    scanf("%d",&n);
    scanf("%s",c+1);
    for(int i=1;i<=n;i++)
    {
        if(c[i]=='B')
        {
            nn[i]=0;
            a++;
        }
        else
        {
            nn[i]=1;
            b++;
        }
    }
    if(a%2==0)
    {
        for(int i=2;i<=n;i++)
        {
            if(nn[i-1]==0)
            {
                nn[i-1]=1;
                nn[i]++;
                nn[i]%=2;
                q.push(i-1);
            }
        }
        printf("%d",q.size());
        if(!q.empty())
        {
            printf("\n");
            while(!q.empty())
            {
                printf("%d ",q.front());
                q.pop();
            }
        }
    }
    else if(b%2==0)
    {
        for(int i=2;i<=n;i++)
        {
            if(nn[i-1]==1)
            {
                nn[i-1]=0;
                nn[i]++;
                nn[i]%=2;
                q.push(i-1);
            }
        }
        printf("%d",q.size());
        if(!q.empty())
        {
            printf("\n");
            while(!q.empty())
            {
                printf("%d ",q.front());
                q.pop();
            }
        }
    }
    else printf("-1");
}
