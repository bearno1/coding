#include<bits/stdc++.h>
#define F first
#define S second
const long long MOD = (long long)(1e9+7);
using namespace std;
int n,tr[100005][3],k[100005],a,b,nx;
vector<int>num[100005];
bitset<100005>uu;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-2;i++)
    {
        k[i]=3;
        scanf("%d %d %d",&tr[i][0],&tr[i][1],&tr[i][2]);
        num[tr[i][0]].push_back(i);
        num[tr[i][1]].push_back(i);
        num[tr[i][2]].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(a==0&&num[i].size()==1)
        {
            a=i;
            for(int j=0;j<num[a].size();j++)
            {
                k[num[a][j]]--;
            }
            printf("%d ",a);
            uu[a]=true;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(b==0&&num[i].size()==2)
        {
            bool p=false;
            for(int j=0;j<num[i].size();j++)
            {
                if(k[num[i][j]]==2)p=true;
            }
            if(p)
            {
                b=i;
                for(int j=0;j<num[b].size();j++)
                {
                    k[num[b][j]]--;
                    if(k[num[b][j]]==1)nx=num[b][j];
                }
                printf("%d ",b);
                uu[b]=true;
            }
        }
    }
    for(int i=3;i<=n;i++)
    {
        int cc;
        for(int j=0;j<3;j++)
        {
            if(!uu[tr[nx][j]])
            {
                cc=tr[nx][j];
            }
        }
        for(int j=0;j<num[cc].size();j++)
        {
            k[num[cc][j]]--;
            if(k[num[cc][j]]==1)nx=num[cc][j];
        }
        printf("%d ",cc);
        uu[cc]=true;
    }
}
