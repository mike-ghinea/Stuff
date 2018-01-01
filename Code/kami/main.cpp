#include <fstream>

#define dim 100010
using namespace std;
ifstream fin("kami.in");
ofstream fout("kami.out");
int i,n,m,v[dim],start,val,poz,OK,sol,a,b;
long long arbsum[4*dim],sum,cost[4*dim];
void update(int nod, int st, int dr)
{
    if(st==dr)
    {
        cost[nod]=arbsum[nod]=val;
        return;
    }
    int mid=(st+dr)/2;
    if(mid>=poz)
        update(2*nod,st,mid);
    else
        update(2*nod+1,mid+1,dr);
    cost[nod]=max(cost[2*nod+1],(cost[2*nod]-arbsum[2*nod+1]));
    arbsum[nod]=arbsum[2*nod]+arbsum[2*nod+1];
}
void query(int nod, int st, int dr)
{
    if(sol)
        return;
    if(st==dr)
    {
        if(cost[nod]>=sum)
            sol=st;
        else
            sum+=arbsum[nod];
        return;
    }
    if(dr<=start)
    {
        if(cost[nod]>=sum)
        {
            if(cost[2*nod+1]>=sum)
                query(2*nod+1,(st+dr)/2+1,dr);
            else
            {
                sum+=arbsum[2*nod+1];
                query(2*nod,st,(st+dr)/2);
            }
        }
        else
            sum+=arbsum[nod];
        return;
    }
    int mid=(st+dr)/2;
    if(mid<start)
        query(2*nod+1,mid+1,dr);
    if(1<=mid)
        query(2*nod,st,mid);
}
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>v[i];
        val=v[i];
        poz=i;
        update(1,1,n);
    }
    fin>>m;
    for(i=1;i<=m;i++)
    {
        fin>>a>>b;
        if(a==1)
        {
            sum=v[b];
            start=b-1;
            sol=0;
            if(start)
                query(1,1,n);
            fout<<sol<<'\n';
        }
        else
        {
            fin>>v[b];
            poz=b;
            val=v[b];
            update(1,1,n);
        }
    }
    return 0;
}
