#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
#define L ((idx*2))
#define R ((idx*2)+1)
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int h,n,l,seq[2000005],cur1,cur2,qq[100005][2],p[500005],r,ans;
set<int>s;
set<int>::iterator it;
void up(int st,int ed,int idx,int pos,int val)
{
   int mid=(st+ed)/2;
   if(pos<p[st]||pos>p[ed])return;
   if(st==ed)
   {
      seq[idx]+=val;
      return;
   }
   up(st,mid,L,pos,val);
   up(mid+1,ed,R,pos,val);
   seq[idx]=max(seq[L],seq[R]);
   return;
}
int main()
{
   scanf("%d %d %d",&n,&h,&l);
   cur1=1;
   cur2=1;
   for(int i=1;i<=n;i++)
   {
      scanf("%d %d",&qq[i][0],&qq[i][1]);
      for(int j=qq[i][1];j>-1&&j>=qq[i][1]-l;j--)
      {
         s.insert(j);
      }
   }
   it=s.begin();
   while(it!=s.end())
   {
      r++;
      p[r]=*it;
      it++;
   }
   while(cur2<=n)
   {
      while(qq[cur2][0]<=qq[cur1][0]+h)
      {
         for(int j=qq[cur2][1];j>-1&&j>=qq[cur2][1]-l;j--)
         {
            up(1,r,1,j,1);
         }
         cur2++;
         if(cur2>n)break;
      }
      ans=max(seq[1],ans);
      for(int j=qq[cur1][1];j>-1&&j>=qq[cur1][1]-l;j--)
      {
         up(1,r,1,j,-1);
      }
      cur1++;
   }
   printf("%d",ans);
}
