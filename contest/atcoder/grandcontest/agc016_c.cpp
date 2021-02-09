#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define PB push_back
#define all(x) (x).begin()s,(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define IMX INT_MAX
const int CON = (int)(1e7);
const long long MMX = (long long)(1e18);
typedef long long LL;
int n,m,a,b,pp[505][505],k;
LL ss;
int main()
{
    scanf("%d %d %d %d",&n,&m,&a,&b);
    k=a*b;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i%a==0&&j%b==0)pp[i][j]=-k-CON,ss-=k+CON;
            else if(i%a==1&&j%b==1||(a==1&&j%b==1)||(b==1&&i%a==1))pp[i][j]=k-1+CON,ss+=k-1+CON;
            else pp[i][j]=0;
        }
    }
    if(ss>0)
    {
        printf("Yes\n");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                printf("%d ",pp[i][j]);
            }
            printf("\n");
        }
    }
    else printf("No");
}
