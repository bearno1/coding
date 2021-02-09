#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
using namespace std;
int n,m,k=300;
struct node
{
   int lv,POS;
   vector<int>ww;
   bool dou=false;
   node *l=NULL,*r=NULL;
}N[200005];
void gen(node *nw,int lv,int warp)
{
   nw->lv=lv;
   if(nw->dou)
   {
      if(warp!=nw->POS)N[warp].ww.push_back(nw->POS);
      gen(nw->l,lv+1,nw->l->POS);
      gen(nw->r,lv+1,nw->r->POS);
      return;
   }
   else if(nw->l==NULL&&nw->r==NULL)
   {
      if(warp!=nw->POS)N[warp].ww.push_back(nw->POS);
      return;
   }
   else
   {
      if(warp!=nw->POS)N[warp].ww.push_back(nw->POS);
      if(nw->l!=NULL)
      {
         gen(nw->l,lv+1,warp);
      }
      if(nw->r!=NULL)
      {
         gen(nw->r,lv+1,warp);
      }
      return;
   }
}
int FIND(node *nw,int L,int s,int a,int b)
{
   if(L<=nw->lv||(nw->l==NULL&&nw->r==NULL))return nw->POS;
   if(nw->dou)
   {
      int res=((s&8)>>3);
      s=(s*a+b)%40507;
      if(res==0)
      {
         return FIND(nw->l,L,s,a,b);
      }
      else
      {
         return FIND(nw->r,L,s,a,b);
      }
   }
   int c=nw->ww.size();
   if(c==0)while(1);
   return FIND(&N[nw->ww[min(c-1,L-nw->lv-1)]],L,s,a,b);
}
int main()
{
   int a,b,L,s;
   scanf("%d %d",&n,&m);
   for(int i=0;i<n;i++)
   {
      N[i].POS=i;
      scanf("%d %d",&a,&b);
      if(a!=-1)
      {
         N[i].l=&N[a];
      }
      if(b!=-1)
      {
         N[i].r=&N[b];
      }
      if(a!=-1&&b!=-1)N[i].dou=true;
   }
   gen(&N[0],0,0);
   //printf("\\\\\\");
   /*for(int i=0;i<n;i++)
   {
      int c=N[i].ww.size();
      if(c!=0)
      {
         printf("----%d\n",i);
         for(int j=0;j<c;j++)
         {
            printf("%d %d\n",N[i].ww[j],N[N[i].ww[j]].lv);
         }
      }
   }*/
   while(m--)
   {
      scanf("%d %d %d %d",&L,&s,&a,&b);
      printf("%d\n",FIND(&N[0],L,s,a,b));
   }
}
