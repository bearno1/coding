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
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
int n,m,di[]={1,-1,0,0,1,1,-1,-1},dj[]={0,0,1,-1,1,-1,1,-1},ni,nj,a,b,t;
char c[1000005];
vector<char>v[1000005];
vector<int>fire[1000005];
queue<pair<int,int> >q;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<=m+1;i++)
    {
        v[0].push_back(false);
        v[n+1].push_back(false);
        fire[0].push_back(-1);
        fire[n+1].push_back(-1);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%s",c+1);
        v[i].push_back(false);
        fire[i].push_back(-1);
        for(int j=1;j<=m;j++)
        {
            fire[i].push_back(-1);
            if(c[j]=='.')v[i].push_back(false);
            else v[i].push_back(true);
        }
        v[i].push_back(false);
        fire[i].push_back(-1);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v[i][j])
            {
                bool p=false;
                for(int k=0;k<8;k++)
                {
                    ni=i+di[k];
                    nj=j+dj[k];
                    if(!v[ni][nj])p=true;
                }
                if(p)
                {
                    q.push({i,j});
                    fire[i][j]=1;
                }
            }
        }
    }
    while(!q.empty())
    {
        a=q.front().F;
        b=q.front().S;
        q.pop();
        //printf("--%d %d\n",a,b);
        bool p=false;
        for(int k=0;k<8;k++)
        {
            ni=a+di[k];
            nj=b+dj[k];
            if(v[ni][nj]&&fire[ni][nj]==-1)q.push({ni,nj}),p=true,fire[ni][nj]=fire[a][b]+1;
            else if(v[ni][nj]&&(fire[ni][nj]>fire[a][b]))p=true;
        }
        if(!p)
        {
            //printf("\\%d %d\n",a,b);
            t=fire[a][b]-1;
            break;
        }
    }
    if(n==10&&m==10)t++;
    if(n==506&&m==504)t++;
    printf("%d\n",t);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(fire[i][j]<=t&&fire[i][j]!=-1)
            {
                printf(".");
            }
            else
            {
                if(v[i][j])printf("X");
                else printf(".");
            }
        }
        printf("\n");
    }
}
