#include <fstream>
#include <limits.h>
#include <string.h>

#define INF LONG_LONG_MAX
#define Ndim 200005
using namespace std;
ifstream fin("haybales.in");
ofstream fout("haybales.out");
int N,Q,start,finish,i,poz;
long long sol,val;
char ch;
struct strct{long long val,lazy;}ARBM[4*Ndim],ARBS[4*Ndim];
void min_build(int nod,int st,int dr)
{
    if(st==dr)
    {
        ARBM[nod].val=val;
        return;
    }
    int mid=(st+dr)/2;
    if(mid >= poz)
        min_build(2*nod,st,mid);
    else
        min_build(2*nod+1,mid+1,dr);
    ARBM[nod].val=min(ARBM[2*nod].val,ARBM[2*nod+1].val);
}
void sum_build(int nod,int st,int dr)
{
    if(st==dr)
    {
        ARBS[nod].val=val;
        return;
    }
    int mid=(st+dr)/2;
    if(mid >= poz)
        sum_build(2*nod,st,mid);
    else
        sum_build(2*nod+1,mid+1,dr);
    ARBS[nod].val=ARBS[2*nod].val+ARBS[2*nod+1].val;
}
void min_update(int nod,int st,int dr)
{
    if(ARBM[nod].lazy!=0)
    {
        ARBM[nod].val+=ARBM[nod].lazy;
        if(st!=dr)
        {
            ARBM[2*nod].lazy+=ARBM[nod].lazy;
            ARBM[2*nod+1].lazy+=ARBM[nod].lazy;
        }
        ARBM[nod].lazy=0;
    }
    if(st >= start && dr <=finish)
    {
        if(st == dr)
        {
            ARBM[nod].val+=val;
            ARBM[nod].lazy=0;
            return;
        }
        ARBM[nod].val+=val;
        ARBM[2*nod].lazy+=val;
        ARBM[2*nod+1].lazy+=val;
        return;
    }
    int mid=(st+dr)/2;
    if(mid >= start)
        min_update(2*nod,st,mid);
    if(mid < finish)
        min_update(2*nod+1,mid+1,dr);
    ARBM[nod].val=min(ARBM[2*nod].val+ARBM[2*nod].lazy,ARBM[2*nod+1].val+ARBM[2*nod+1].lazy);
}
void sum_update(int nod,int st,int dr)
{
    if(ARBS[nod].lazy!=0)
    {
        ARBS[nod].val+=ARBS[nod].lazy;
        if(st!=dr)
        {
            ARBS[2*nod].lazy+=ARBS[nod].lazy;
            ARBS[2*nod+1].lazy+=ARBS[nod].lazy;
        }
        ARBS[nod].lazy=0;
    }
    if(st >= start && dr <=finish)
    {
        if(st == dr)
        {
            ARBS[nod].val+=val;
            ARBS[nod].lazy=0;
            return;
        }
        ARBS[2*nod].lazy+=((st+dr)/2-st+1)*val;
        ARBS[2*nod+1].lazy+=(dr-(st+dr)/2)*val;
        ARBS[nod].val+=(dr-st+1)*val;
        return;
    }
    int mid=(st+dr)/2;
    if(mid >= start)
        sum_update(2*nod,st,mid);
    if(mid < finish)
        sum_update(2*nod+1,mid+1,dr);
    ARBS[nod].val=ARBS[2*nod].val+ARBS[2*nod].lazy+ARBS[2*nod+1].val+ARBS[2*nod+1].lazy;
}
void min_query(int nod,int st,int dr)
{
    if(ARBM[nod].lazy!=0)
    {
        ARBM[nod].val+=ARBM[nod].lazy;
        if(st!=dr)
        {
            ARBM[2*nod].lazy+=ARBM[nod].lazy;
            ARBM[2*nod+1].lazy+=ARBM[nod].lazy;
        }
        ARBM[nod].lazy=0;
    }
    if(st >= start && dr <=finish)
    {
        sol=min(sol,ARBM[nod].val);
        return;
    }
    int mid=(st+dr)/2;
    if(mid >= start)
        min_query(2*nod,st,mid);
    if(mid < finish)
        min_query(2*nod+1,mid+1,dr);
}
void sum_query(int nod,int st,int dr)
{
    if(ARBS[nod].lazy!=0)
    {
        ARBS[nod].val+=((dr-st+1)*ARBS[nod].lazy);
        if(st!=dr)
        {
            ARBS[2*nod].lazy+=ARBS[nod].lazy;
            ARBS[2*nod+1].lazy+=ARBS[nod].lazy;
        }
        ARBS[nod].lazy=0;
    }
    if(st >= start && dr <= finish)
    {
        sol+=ARBS[nod].val;
        return;
    }
    int mid=(st+dr)/2;
    if(mid >= start)
        sum_query(2*nod,st,mid);
    if(mid < finish)
        sum_query(2*nod+1,mid+1,dr);
}
int main()
{
    fin>>N>>Q;
    for(i=1;i<=4*N;i++)
        ARBM[i].val=INF;
    for(i=1;i<=N;i++)
    {
        fin>>val;
        poz=i;
        min_build(1,1,N);
        sum_build(1,1,N);
    }
    for(i=1;i<=Q;i++)
    {
        fin>>ch;
        if(ch=='P')
        {
            fin>>start>>finish>>val;
            min_update(1,1,N);
            sum_update(1,1,N);
            continue;
        }
        if(ch=='M')
        {
            fin>>start>>finish;
            sol=INF;
            min_query(1,1,N);
            fout<<sol<<'\n';
            continue;
        }
        fin>>start>>finish;
        sol=0;
        sum_query(1,1,N);
        fout<<sol<<'\n';
    }
    return 0;
}
