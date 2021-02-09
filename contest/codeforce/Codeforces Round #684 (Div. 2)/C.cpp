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
int t,n,m;
char c[105][105],cp[105][105];
vector<pii>v[3],one,ze;
int main()
{
    scanf("%d",&t);
    for(int tt=0;tt<t;tt++)
    {
        v[0].clear();
        v[1].clear();
        v[2].clear();
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cp[i][j]=c[i][j];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int co=-1;
                if(n==2&&m==2)i=n,j=m;
                if(i==n&&j==m)
                {
                    while(co!=0)
                    {
                        one.clear(),ze.clear();
                        co=0;
                        if(c[i][j]=='1')co++,one.pb({i,j});
                        else ze.pb({i,j});
                        if(c[i][j-1]=='1')co++,one.pb({i,j-1});
                        else ze.pb({i,j-1});
                        if(c[i-1][j]=='1')co++,one.pb({i-1,j});
                        else ze.pb({i-1,j});
                        if(c[i-1][j-1]=='1')co++,one.pb({i-1,j-1});
                        else ze.pb({i-1,j-1});
                        if(co==4)
                        {
                            v[0].pb({i,j});
                            v[1].pb({i-1,j});
                            v[2].pb({i,j-1});
                            if(c[i][j]=='0')c[i][j]='1';
                            else c[i][j]='0';
                            if(c[i][j-1]=='0')c[i][j-1]='1';
                            else c[i][j-1]='0';
                            if(c[i-1][j]=='0')c[i-1][j]='1';
                            else c[i-1][j]='0';
                        }
                        else if(co==1)
                        {
                            v[0].pb({ze[0].F,ze[0].S});
                            v[1].pb({ze[1].F,ze[1].S});
                            v[2].pb({one[0].F,one[0].S});
                            if(c[ze[0].F][ze[0].S]=='0')c[ze[0].F][ze[0].S]='1';
                            else c[ze[0].F][ze[0].S]='0';
                            if(c[ze[1].F][ze[1].S]=='0')c[ze[1].F][ze[1].S]='1';
                            else c[ze[1].F][ze[1].S]='0';
                            if(c[one[0].F][one[0].S]=='0')c[one[0].F][one[0].S]='1';
                            else c[one[0].F][one[0].S]='0';
                        }
                        else if(co==2)
                        {
                            v[0].pb({ze[0].F,ze[0].S});
                            v[1].pb({ze[1].F,ze[1].S});
                            v[2].pb({one[0].F,one[0].S});
                            if(c[ze[0].F][ze[0].S]=='0')c[ze[0].F][ze[0].S]='1';
                            else c[ze[0].F][ze[0].S]='0';
                            if(c[ze[1].F][ze[1].S]=='0')c[ze[1].F][ze[1].S]='1';
                            else c[ze[1].F][ze[1].S]='0';
                            if(c[one[0].F][one[0].S]=='0')c[one[0].F][one[0].S]='1';
                            else c[one[0].F][one[0].S]='0';
                        }
                        else if(co==3)
                        {
                            v[0].pb({one[0].F,one[0].S});
                            v[1].pb({one[1].F,one[1].S});
                            v[2].pb({one[2].F,one[2].S});
                            if(c[one[0].F][one[0].S]=='0')c[one[0].F][one[0].S]='1';
                            else c[one[0].F][one[0].S]='0';
                            if(c[one[1].F][one[1].S]=='0')c[one[1].F][one[1].S]='1';
                            else c[one[1].F][one[1].S]='0';
                            if(c[one[2].F][one[2].S]=='0')c[one[2].F][one[2].S]='1';
                            else c[one[2].F][one[2].S]='0';
                        }
                    }
                }
                else if(i==n)
                {
                    if(c[i][j]=='0'&&c[i-1][j]=='0')continue;
                    if(c[i][j]=='1'&&c[i-1][j]=='1')
                    {
                        v[0].pb({i,j});
                        v[1].pb({i-1,j});
                        v[2].pb({i,j+1});
                        c[i][j]='0';
                        c[i-1][j]='0';
                        if(c[i][j+1]=='0')c[i][j+1]='1';
                        else c[i][j+1]='0';
                    }
                    else if(c[i][j]=='1')
                    {
                        v[0].pb({i,j});
                        v[1].pb({i,j+1});
                        v[2].pb({i-1,j+1});
                        c[i][j]='0';
                        if(c[i][j+1]=='0')c[i][j+1]='1';
                        else c[i][j+1]='0';
                        if(c[i-1][j+1]=='0')c[i-1][j+1]='1';
                        else c[i-1][j+1]='0';
                    }
                    else
                    {
                        v[0].pb({i-1,j});
                        v[1].pb({i-1,j+1});
                        v[2].pb({i,j+1});
                        c[i-1][j]='0';
                        if(c[i-1][j+1]=='0')c[i-1][j+1]='1';
                        else c[i-1][j+1]='0';
                        if(c[i][j+1]=='0')c[i][j+1]='1';
                        else c[i][j+1]='0';
                    }
                }
                else if(j==m)
                {
                    if(c[i][j]=='0')continue;
                    v[0].pb({i,j});
                    v[1].pb({i+1,j});
                    v[2].pb({i+1,j-1});
                    c[i][j]='0';
                    if(c[i+1][j]=='0')c[i+1][j]='1';
                    else c[i+1][j]='0';
                    if(c[i+1][j-1]=='0')c[i+1][j-1]='1';
                    else c[i+1][j-1]='0';
                }
                else
                {
                    one.clear(),ze.clear();
                    co=0;
                    if(c[i][j]=='1')co++,one.pb({i,j});
                    else ze.pb({i,j});
                    if(c[i][j+1]=='1')co++,one.pb({i,j+1});
                    else ze.pb({i,j+1});
                    if(c[i+1][j]=='1')co++,one.pb({i+1,j});
                    else ze.pb({i+1,j});
                    if(c[i+1][j+1]=='1')co++,one.pb({i+1,j+1});
                    else ze.pb({i+1,j+1});
                    if(co==3)
                    {
                        v[0].pb({one[0].F,one[0].S});
                        v[1].pb({one[1].F,one[1].S});
                        v[2].pb({one[2].F,one[2].S});
                        if(c[one[0].F][one[0].S]=='0')c[one[0].F][one[0].S]='1';
                        else c[one[0].F][one[0].S]='0';
                        if(c[one[1].F][one[1].S]=='0')c[one[1].F][one[1].S]='1';
                        else c[one[1].F][one[1].S]='0';
                        if(c[one[2].F][one[2].S]=='0')c[one[2].F][one[2].S]='1';
                        else c[one[2].F][one[2].S]='0';
                    }
                    if(c[i][j]=='0')continue;
                    v[0].pb({i,j});
                    v[1].pb({i,j+1});
                    v[2].pb({i+1,j+1});
                    c[i][j]='0';
                    if(c[i][j+1]=='0')c[i][j+1]='1';
                    else c[i][j+1]='0';
                    if(c[i+1][j+1]=='0')c[i+1][j+1]='1';
                    else c[i+1][j+1]='0';
                }
                int tp=v[0].size()-1;
                // printf("%d %d %d %d %d %d\n",v[0][tp].F,v[0][tp].S,v[1][tp].F,v[1][tp].S,v[2][tp].F,v[2][tp].S);
                // for(int ii=1;ii<=n;ii++)
                // {
                //     for(int jj=1;jj<=m;jj++)
                //     {
                //         printf("%c",c[ii][jj]);
                //     }
                //     printf("\n");
                // }
            }
        }
        if(v[0].size()>n*m)
        {
            v[0].clear();
            v[1].clear();
            v[2].clear();
            for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)c[i][j]=cp[i][j];
            for(int i=2;i<=n;i++)
            {
                for(int j=2;j<=m;j++)
                {
                    if(true)
                    {
                        int co=-1;
                        while(co!=0)
                        {
                            one.clear(),ze.clear();
                            co=0;
                            if(c[i][j]=='1')co++,one.pb({i,j});
                            else ze.pb({i,j});
                            if(c[i][j-1]=='1')co++,one.pb({i,j-1});
                            else ze.pb({i,j-1});
                            if(c[i-1][j]=='1')co++,one.pb({i-1,j});
                            else ze.pb({i-1,j});
                            if(c[i-1][j-1]=='1')co++,one.pb({i-1,j-1});
                            else ze.pb({i-1,j-1});
                            if(co==4)
                            {
                                v[0].pb({i,j});
                                v[1].pb({i-1,j});
                                v[2].pb({i,j-1});
                                if(c[i][j]=='0')c[i][j]='1';
                                else c[i][j]='0';
                                if(c[i][j-1]=='0')c[i][j-1]='1';
                                else c[i][j-1]='0';
                                if(c[i-1][j]=='0')c[i-1][j]='1';
                                else c[i-1][j]='0';
                            }
                            else if(co==1)
                            {
                                v[0].pb({ze[0].F,ze[0].S});
                                v[1].pb({ze[1].F,ze[1].S});
                                v[2].pb({one[0].F,one[0].S});
                                if(c[ze[0].F][ze[0].S]=='0')c[ze[0].F][ze[0].S]='1';
                                else c[ze[0].F][ze[0].S]='0';
                                if(c[ze[1].F][ze[1].S]=='0')c[ze[1].F][ze[1].S]='1';
                                else c[ze[1].F][ze[1].S]='0';
                                if(c[one[0].F][one[0].S]=='0')c[one[0].F][one[0].S]='1';
                                else c[one[0].F][one[0].S]='0';
                            }
                            else if(co==2)
                            {
                                v[0].pb({ze[0].F,ze[0].S});
                                v[1].pb({ze[1].F,ze[1].S});
                                v[2].pb({one[0].F,one[0].S});
                                if(c[ze[0].F][ze[0].S]=='0')c[ze[0].F][ze[0].S]='1';
                                else c[ze[0].F][ze[0].S]='0';
                                if(c[ze[1].F][ze[1].S]=='0')c[ze[1].F][ze[1].S]='1';
                                else c[ze[1].F][ze[1].S]='0';
                                if(c[one[0].F][one[0].S]=='0')c[one[0].F][one[0].S]='1';
                                else c[one[0].F][one[0].S]='0';
                            }
                            else if(co==3)
                            {
                                v[0].pb({one[0].F,one[0].S});
                                v[1].pb({one[1].F,one[1].S});
                                v[2].pb({one[2].F,one[2].S});
                                if(c[one[0].F][one[0].S]=='0')c[one[0].F][one[0].S]='1';
                                else c[one[0].F][one[0].S]='0';
                                if(c[one[1].F][one[1].S]=='0')c[one[1].F][one[1].S]='1';
                                else c[one[1].F][one[1].S]='0';
                                if(c[one[2].F][one[2].S]=='0')c[one[2].F][one[2].S]='1';
                                else c[one[2].F][one[2].S]='0';
                            }
                        }
                    }
                }
            }
            printf("%d\n",v[0].size());
            if(v[0].size()>n*m)while(1)printf("error");
            for(int i=0;i<v[0].size();i++)
            {
                printf("%d %d %d %d %d %d\n",v[0][i].F,v[0][i].S,v[1][i].F,v[1][i].S,v[2][i].F,v[2][i].S);
            }
        }
        else
        {
            printf("%d\n",v[0].size());
            for(int i=0;i<v[0].size();i++)
            {
                printf("%d %d %d %d %d %d\n",v[0][i].F,v[0][i].S,v[1][i].F,v[1][i].S,v[2][i].F,v[2][i].S);
            }
        }
    }
}
