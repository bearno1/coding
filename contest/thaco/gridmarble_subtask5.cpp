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
int n,m,a,b,k,qs[2][100005][2],dw=1;
char c[3][100005];
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
    for(int j=1;j<=m;j++)
    {
        qs[0][j][0]=qs[0][j-1][0];
        qs[0][j][1]=qs[0][j-1][1];
        if(c[1][j]=='G')
        {
            qs[0][j][0]++;
        }
        else
        {
            qs[0][j][1]++;
        }
    }
    for(int j=m;j>0;j--)
    {
        qs[1][j][0]=qs[1][j+1][0];
        qs[1][j][1]=qs[1][j+1][1];
        if(c[2][j]=='G')
        {
            qs[1][j][0]++;
        }
        else
        {
            qs[1][j][1]++;
        }
    }
    k=0;
    for(int i=1;i<=m;i++)
    {
        int val=min(qs[0][i][0]+qs[1][i][0],qs[0][i][1]+qs[1][i][1]);
        if(val>k)
        {
            k=val;
            dw=i;
        }
    }
    printf("%d\n",k*2);
    for(int i=1;i<=dw;i++)
    {
        if(c[1][i]=='G')
        {
            if(a<k)a++,printf("Y ");
            else printf("N ");
        }
        else
        {
            if(b<k)b++,printf("Y ");
            else printf("N ");
        }
        if(i!=dw)printf("R");
        else printf("D");
        printf("\n");
    }
    for(int i=dw;i<=m;i++)
    {
        if(c[2][i]=='G')
        {
            if(a<k)a++,printf("Y ");
            else printf("N ");
        }
        else
        {
            if(b<k)b++,printf("Y ");
            else printf("N ");
        }
        if(i!=m)printf("R");
        printf("\n");
    }
}
