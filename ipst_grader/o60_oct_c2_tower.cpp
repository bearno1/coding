#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
using namespace std;
long long x;
int n,m,a,b;
struct node
{
   long long val=1,lazy=0,LL=0,RR=0,MX=0;
   int st,ed;
   node *l=NULL,*r=NULL;
}s;
node *S=&s;
void con(node *now)
{
   int mid=(now->st+now->ed)/2;
   if(now->st!=now->ed)
   {
      node *nn=new node;
      now->l=nn;
      nn->st=now->st;
      nn->ed=mid;
      con(nn);
      nn=new node;
      now->r=nn;
      nn->st=mid+1;
      nn->ed=now->ed;
      con(nn);
   }
   return;
}
void UP(node *now)
{
   if(now->lazy!=0)
   {
      now->MX+=now->lazy;
      now->LL+=now->lazy;
      now->RR+=now->lazy;
      if(now->st!=now->ed)
      {
         (now->l)->lazy+=now->lazy;
         (now->r)->lazy+=now->lazy;
      }
      now->lazy=0;
   }
   if((now->st)>b||(now->ed)<a)return;
   if((now->st)>=a&&(now->ed)<=b)
   {
      now->MX+=x;
      now->LL+=x;
      now->RR+=x;
      if(now->st!=now->ed)
      {
         (now->l)->lazy+=x;
         (now->r)->lazy+=x;
      }
      //printf("==\\%d %d %lld %lld\n",now->st,now->ed,now->MX,now->val);
      return;
   }
   UP(now->l);
   UP(now->r);
   now->MX=max((now->l)->MX,(now->r)->MX);
   now->LL=(now->l)->LL;
   now->RR=(now->r)->RR;
   if(((now->l)->RR==(now->r)->LL)&&((now->l)->MX==(now->r)->MX))
   {
      if((now->l)->MX==(now->l)->RR)
      {
         now->val=(now->l)->val+(now->r)->val-1;
      }
      else
      {
         if((now->l)->MX>(now->r)->MX)now->val=(now->l)->val;
         else if((now->l)->MX==(now->r)->MX)now->val=(now->l)->val+(now->r)->val;
         else now->val=(now->r)->val;
      }
   }
   else
   {
      if((now->l)->MX>(now->r)->MX)now->val=(now->l)->val;
      else if((now->l)->MX==(now->r)->MX)now->val=(now->l)->val+(now->r)->val;
      else now->val=(now->r)->val;
   }
   //printf("==%d %d %lld %lld\n",now->st,now->ed,now->MX,now->val);
   return;
}
int main()
{
   scanf("%d %d",&n,&m);
   s.st=1;
   s.ed=n;
   con(S);
   for(int i=1;i<=m;i++)
   {
      scanf("%d %d %lld",&a,&b,&x);
      UP(S);
      printf("%lld %lld\n",s.MX,s.val);
   }
}
