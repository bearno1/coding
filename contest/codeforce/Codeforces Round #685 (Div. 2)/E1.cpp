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
int n,a,b,ans[70005][20],mul[20],pr[70005],tp[20];
int main()
{
    mul[0]=1;
    for(int i=1;i<20;i++)mul[i]=mul[i-1]*2;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        printf("XOR 1 %d\n",i);
        fflush(stdout);
        scanf("%d",&a);
        fflush(stdout);
        for(int j=0;j<20;j++)
        {
            ans[i][j]=a%2;
            a/=2;
        }
    }
    printf("AND 1 2\n");
    fflush(stdout);
    scanf("%d",&a);
    fflush(stdout);
    for(int j=0;j<20;j++)
    {
        if(a%2==1)
        {
            ans[1][j]=1;
        }
        a/=2;
    }
    printf("AND 2 3\n");
    fflush(stdout);
    scanf("%d",&a);
    fflush(stdout);
    for(int j=0;j<20;j++)
    {
        if(a%2==1)
        {
            tp[j]=1;
        }
        a/=2;
    }
    for(int j=0;j<20;j++)
    {
        if(tp[j]==1)
        {
            if(ans[2][j]==0)ans[1][j]=1;
        }
        else
        {
            ans[1][j]=1;
        }
    }
    for(int j=0;j<20;j++)
    {
        pr[1]+=mul[j]*ans[1][j];
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<20;j++)
        {
            if(ans[i][j]==1&&ans[1][j]==0)
            {
                pr[i]+=mul[j];
            }
            else if(ans[i][j]==0)
            {
                pr[i]+=mul[j]*ans[1][j];
            }
        }
    }
    fflush(stdout);
    printf("! ");
    fflush(stdout);
    for(int i=1;i<=n;i++)printf("%d ",pr[i]);
    //fflush(stdout);
}
