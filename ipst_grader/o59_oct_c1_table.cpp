#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
using namespace std;
int n,m,t,op,i1,i2,i3;
struct node
{
   int Al,Ar,Bl,Br,lazy,MX=0;
   bool lz=false;
   node *l=NULL,*r=NULL;
}s;
node *S = &s;
void llz(node *N,int val)
{
   if(N->lz)
   {
      N->lz=false;
      N->MX=N->lazy;
      if(N->Bl!=N->Br)
      {
         N->l->lz=true;
         N->r->lz=true;
         N->l->lazy=N->lazy;
         N->r->lazy=N->lazy;
      }
      return;
   }
   N->lz=false;
   N->MX=val;
   if(N->Bl!=N->Br)
   {
      N->l->lz=true;
      N->r->lz=true;
      N->l->lazy=val;
      N->r->lazy=val;
   }
   return;
}
void cons(node *N)
{
   int mid1=(N->Al+N->Ar)/2,mid2=(N->Bl+N->Br)/2;
   //printf("---%d %d %d %d\n",N->Al,N->Ar,N->Bl,N->Br);
   if(N->Bl==N->Br&&N->Al&&N->Ar)return;
   if(N->Al==N->Ar)
   {
      node *nn = new node;
      N->l=nn;
      N->l->Al=N->Al;
      N->l->Ar=N->Ar;
      N->l->Bl=N->Bl;
      N->l->Br=mid2;
      cons(nn);
      nn = new node;
      N->r=nn;
      N->r->Al=N->Al;
      N->r->Ar=N->Ar;
      N->r->Bl=mid2+1;
      N->r->Br=N->Br;
      cons(nn);
      return;
   }
   node *nn = new node;
   N->l=nn;
   N->l->Al=N->Al;
   N->l->Ar=mid1;
   N->l->Bl=N->Bl;
   N->l->Br=N->Br;
   cons(nn);
   nn = new node;
   N->r=nn;
   N->r->Al=mid1+1;
   N->r->Ar=N->Ar;
   N->r->Bl=N->Bl;
   N->r->Br=N->Br;
   cons(nn);
   return;
}
void UP(int a1,int b1,int a2,int b2,node *N,int k)
{
   if(N->lz)llz(N,0);
   if(b1<N->Al||a1>N->Ar||b2<N->Bl||a2>N->Br)return;
   if(a1<=N->Al&&b1>=N->Ar&&a2<=N->Bl&&b2>=N->Br)
   {
      N->lz=false;
      llz(N,k);
      return;
   }
   UP(a1,b1,a2,b2,N->l,k);
   UP(a1,b1,a2,b2,N->r,k);
   N->MX=min(N->l->MX,N->r->MX);
   return;
}
int MN(int a1,int b1,int a2,int b2,node *N)
{
   if(N->lz)llz(N,0);
   //printf("---%d %d %d %d\n",N->Al,N->Ar,N->Bl,N->Br);
   if((b1<N->Al||a1>N->Ar)||(b2<N->Bl||a2>N->Br))return 2000000000;
   //printf("----------\n");
   if(a1<=N->Al&&b1>=N->Ar&&a2<=N->Bl&&b2>=N->Br)return N->MX;
   return min(MN(a1,b1,a2,b2,N->l),MN(a1,b1,a2,b2,N->r));
}
int main()
{
   scanf("%d %d %d",&n,&m,&t);
   S->Al=1;
   S->Ar=n;
   S->Bl=1;
   S->Br=m;
   cons(S);
   while(t--)
   {
      scanf("%d",&op);
      if(op==1)
      {
         scanf("%d %d %d",&i1,&i2,&i3);
         UP(i1,i1,i2,i2,S,i3);
      }
      else if(op==2)
      {
         scanf("%d %d",&i1,&i3);
         UP(i1,i1,1,m,S,i3);
      }
      else if(op==3)
      {
         scanf("%d %d",&i1,&i2);
         printf("%d\n",MN(i1,i1,i2,i2,S));
      }
      else
      {
         printf("%d\n",MN(1,n,1,m,S));
      }
   }
}
/*
3 3 14
3 1 2
4
2 1 100
2 2 10
2 3 40
4
1 2 1 50
1 2 3 200
4
1 3 3 25
3 3 2 4
1 2 2 60
4
*/
