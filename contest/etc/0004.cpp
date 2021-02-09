#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define imx INT_MAX
typedef long long LL;
typedef pair<int,int> pii;
int n,x[105],my,co,mx,y[105],cc,tt;
char pr[105][20005],chr[20][20];
int main()
{
    scanf("%d",&n);
    mx=5;
    tt=1;
    while(scanf("%d",&cc)!=EOF)
    {
        if(tt<=n)x[tt]=cc;
        else y[tt-n]=cc;
        tt++;
    }
    if(tt<=n*2)
    {
        printf("0");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        mx=max(x[i],mx);
    }
    for(int i=0;i<20;i++)for(int j=0;j<20;j++)chr[i][j]=' ';
    for(int i=0;i<105;i++)for(int j=0;j<20005;j++)pr[i][j]=' ';
    chr[0][1]='*';
    chr[0][2]='*';
    chr[0][3]='*';
    chr[0][4]='*';
    chr[0][5]='*';
    chr[0][6]='*';
    chr[0][7]='*';
    chr[0][8]='*';
    chr[0][9]='*';
    chr[0][10]='*';
    chr[0][11]='*';
    chr[1][6]='|';
    chr[2][3]='-';
    chr[2][4]='o';
    chr[2][5]='x';
    chr[2][6]='o';
    chr[2][7]='x';
    chr[2][8]='o';
    chr[2][9]='-';
    chr[3][4]='-';
    chr[3][5]='o';
    chr[3][6]='x';
    chr[3][7]='o';
    chr[3][8]='-';
    chr[4][5]='-';
    chr[4][6]='o';
    chr[4][7]='-';
    chr[5][6]='-';
    for(int i=1;i<n;i++)
    {
        for(int ii=0;ii<=x[i];ii++)
        {
            for(int jj=1;jj<=y[i];jj++)
            {
                pr[ii][jj+my]='*';
            }
        }
        my+=y[i];
        for(int ii=0;ii<=5;ii++)
        {
            for(int jj=1;jj<=11;jj++)
            {
                pr[ii][jj+my]=chr[ii][jj];
            }
        }
        my+=11;
    }
    for(int ii=0;ii<=x[n];ii++)
    {
        for(int jj=1;jj<=y[n];jj++)
        {
            pr[ii][jj+my]='*';
        }
    }
    my+=y[n];
    for(int i=mx;i>-1;i--)
    {
        for(int j=1;j<=my;j++)
        {
            printf("%c",pr[i][j]);
            if(pr[i][j]=='*')co++;
        }
        printf("\n");
    }
    printf("%d",co);
}
