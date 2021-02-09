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
int n,m,dw=1,fr[205][205][405],k=-1,a,b,tt,dd;
char c[205][205];
bitset<405>cc[205][205];
void dfs(int ii,int jj,int con)
{
    bool p=false;
    if(fr[ii][jj][con]==1)p=true;
    if(c[ii][jj]=='G')
    {
        con--;
        if(a<k)a++,printf("Y ");
        else printf("N ");
    }
    else
    {
        if(b<k)b++,printf("Y ");
        else printf("N ");
    }
    //printf("{%d %d %d}\n",ii,jj,fr[ii][jj]);
    if(ii==n&&jj==m)return;
    if(p)printf("R\n"),dfs(ii,jj+1,con);
    else printf("D\n"),dfs(ii+1,jj,con);
    return;
}
int main()
{
    scanf("%d %d",&n,&m);
    cc[n+1][m][0]=true;
    cc[n][m+1][0]=true;
    tt=n+m-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",c[i]+1);
    }
    for(int i=n;i>0;i--)
    {
        for(int j=m;j>0;j--)
        {
            //printf("%c %d %d\n",c[i][j],i,j);
            if(c[i][j]=='G')
            {
                for(int co=1;co<405;co++)
                {
                    if(cc[i+1][j][co-1])cc[i][j][co]=true,fr[i][j][co]=0;
                    else if(cc[i][j+1][co-1])cc[i][j][co]=true,fr[i][j][co]=1;
                }
            }
            else
            {
                for(int co=0;co<405;co++)
                {
                    if(cc[i+1][j][co])cc[i][j][co]=true,fr[i][j][co]=0;
                    else if(cc[i][j+1][co])cc[i][j][co]=true,fr[i][j][co]=1;
                }
            }
        }
    }
    for(int co=0;co<405;co++)
    {
        if(cc[1][1][co])
        {
            if(k<min(co,tt-co))k=min(co,tt-co),dd=co;
        }
    }
    printf("%d\n",k*2);
    dfs(1,1,dd);
}
