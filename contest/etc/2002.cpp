#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
typedef long long LL;
typedef pair<int,int> pii;
int t,n,m,wi,sn,sm,hn,hm,stf,nn,mm,dn[]={1,-1,0,0},dm[]={0,0,-1,1},ans[30][30],k;
bool go[30][30];
queue<pair<int,int> >q;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<30;i++)for(int j=0;j<30;j++)go[i][j]=false,ans[i][j]=imx;
        scanf("%d %d",&m,&n);
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)go[i][j]=true;
        scanf("%d %d",&sn,&sm);
        scanf("%d %d",&hn,&hm);
        scanf("%d",&wi);
        scanf("%d",&stf);
        for(int i=1;i<=stf;i++)
        {
            scanf("%d %d",&nn,&mm);
            go[nn][mm]=false;
        }
        ans[sn][sm]=0;
        q.push({sn,sm});
        while(!q.empty())
        {
            nn=q.front().F;
            mm=q.front().S;
            q.pop();
            for(int i=0;i<4;i++)
            {
                sn=nn+dn[i];
                sm=mm+dm[i];
                if(!go[sn][sm])continue;
                if(ans[sn][sm]!=imx)continue;
                ans[sn][sm]=ans[nn][mm]+1;
                q.push({sn,sm});
                printf("{%d %d}",sn,sm);
            }
        }
        k=0;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(ans[i][j]<=wi)k++;
        if(ans[hn][hm]<=wi)printf("Y %d\n",k);
        else printf("N 0\n");
        printf("[%d]\n",ans[hn][hm]);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(ans[i][j]>wi&&go[i][j])printf("   ");
                else if(!go[i][j])printf(" * ");
                else if(i==hn&&j==hm)printf("[%d]",ans[i][j]);
                else printf(" %d ",ans[i][j]);
            }
            printf("\n");
        }
    }
}
