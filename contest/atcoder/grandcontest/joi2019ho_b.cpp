#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
int n,m,a,b,r;
vector<int>ss;
vector<pair<int,int> >pic;
vector<pair<int,int> >lis;
vector<pair<int,int> >::iterator it;
pair<int,int>pp,cc;
int main()
{
   scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++)
   {
      scanf("%d %d",&a,&b);
      pic.push_back({a,b});
   }
   for(int i=1;i<=m;i++)
   {
      scanf("%d",&a);
      ss.push_back(a);
   }
   sort(pic.begin(),pic.end());
   sort(ss.begin(),ss.end());
   for(int i=0;i<n;i++)
   {
      while(pic[i].first>ss[r])
      {
         if(r>=m)break;
         r++;
      }
      if(r>=m)continue;
      else
      {
         pp={pic[i].S,ss[r]};
         it=upper_bound(lis.begin(),lis.end(),pp);
         if(it!=lis.end())cc=*it;
         if(it==lis.end())lis.push_back(pp),r++;
         else
         {
            if(cc.S>=pic[i].F)
            {
               *it=pp;
               if(cc.S!=ss[r])r++;
            }
         }
      }
      printf("====== %d\n",i);
      for(int i=0;i<lis.size();i++)
      {
         printf("%d %d\n",lis[i].F,lis[i].S);
      }
   }
   printf("%d",lis.size());
}
