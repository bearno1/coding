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
char c[10],pr[505][505];
int n,p,ro[2][505][2],co[2][505][2];
void gen(int *a,int *b)
{
    int tp=strlen(c);
    if(tp==1)
    {
        if(c[0]=='-')*a=-1,*b=-1;
        if(c[0]=='0')*a=n+1,*b=-1;
    }
    else
    {
        int di=0;
        for(int j=0;j<tp-1;j++)
        {
            di*=10;
            di+=c[j]-'0';
        }
        *a=di;
        if(c[tp-1]=='B')*b=1;
        else *b=2;
    }
    return;
}
int main()
{
    // freopen("pajel_1.in","r",stdin);
    // freopen("pajel_1.out","w",stdout);
    scanf("%d %d",&n,&p);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",c);
        gen(&co[0][i][0],&co[0][i][1]);
        //printf("co0[%d]\n",ro[0][i][0]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%s",c);
        gen(&ro[0][i][0],&ro[0][i][1]);
        //printf("ro0[%d]\n",ro[0][i][0]);
        scanf("%s",c);
        gen(&ro[1][i][0],&ro[1][i][1]);
        ro[1][i][0]=n-ro[1][i][0]+1;
        //printf("ro1[%d]\n",ro[1][i][0]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%s",c);
        gen(&co[1][i][0],&co[1][i][1]);
        co[1][i][0]=n-co[1][i][0]+1;
        //printf("co1[%d]\n",co[1][i][0]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)pr[i][j]='-';
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i<co[0][j][0]||i>co[1][j][0]||j<ro[0][i][0]||j>ro[1][i][0])continue;
            if((i==co[0][j][0]&&co[0][j][1]==2)
            ||(i==co[1][j][0]&&co[1][j][1]==2)
            ||(j==ro[0][i][0]&&ro[0][i][1]==2)
            ||(j==ro[1][i][0]&&ro[1][i][1]==2))pr[i][j]='M';
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i<co[0][j][0]||i>co[1][j][0]||j<ro[0][i][0]||j>ro[1][i][0])continue;
            if((i==co[0][j][0]&&co[0][j][1]==1)
            ||(i==co[1][j][0]&&co[1][j][1]==1)
            ||(j==ro[0][i][0]&&ro[0][i][1]==1)
            ||(j==ro[1][i][0]&&ro[1][i][1]==1))pr[i][j]='B';
        }
    }
    for(int t=1;t<=100;t++)
    {
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(pr[i][j]!='-')continue;
            if(i<co[0][j][0]||i>co[1][j][0]||j<ro[0][i][0]||j>ro[1][i][0])continue;
            if(pr[i-1][j]=='B'||pr[i+1][j]=='B'||pr[i][j-1]=='B'||pr[i][j+1]=='B')pr[i][j]='B';
            else if(pr[i-1][j]=='M'||pr[i+1][j]=='M'||pr[i][j-1]=='M'||pr[i][j+1]=='M')pr[i][j]='M';
        }
    }
    for(int i=n;i>0;i--)
    {
        for(int j=n;j>0;j--)
        {
            if(pr[i][j]!='-')continue;
            if(i<co[0][j][0]||i>co[1][j][0]||j<ro[0][i][0]||j>ro[1][i][0])continue;
            if(pr[i-1][j]=='B'||pr[i+1][j]=='B'||pr[i][j-1]=='B'||pr[i][j+1]=='B')pr[i][j]='B';
            else if(pr[i-1][j]=='M'||pr[i+1][j]=='M'||pr[i][j-1]=='M'||pr[i][j+1]=='M')pr[i][j]='M';
        }
    }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)printf("%c",pr[i][j]);
        printf("\n");
    }
}
