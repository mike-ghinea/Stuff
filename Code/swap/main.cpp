#include <fstream>
#include <string.h>
#define dim 50001
using namespace std;
ifstream fin("swap.in");
ofstream fout("swap.out");

char s1[dim],s2[dim];
int n,arb[4*dim],i,sol,a[27][dim],poz,start,finish;
void update(int nod, int st, int dr)
{
    if(st==dr)
    {
        arb[nod]++;
        return;
    }
    int mij = (st+dr)/2;
    if(poz<=mij)
        update(2*nod,st,mij);
    else
        update(2*nod+1,mij+1,dr);
    arb[nod]++;
}
void query(int nod, int st, int dr)
{
    if(st>=start && dr<=finish)
    {
        sol+=arb[nod];
        return;
    }
    int mij = (st+dr)/2;
    if(start <= mij)
        query(2*nod, st, mij);
    if(finish>mij)
        query(2*nod+1, mij+1,dr);

}
int main()
{
    fin>>(s1+1)>>(s2+1);
    n=strlen(s1+1);
    for(i=1;i<=n;i++)
        a[s1[i]-'a'][++a[s1[i]-'a'][0]]=i;
    for(i=1;i<=n;i++)
    {
        if(a[s2[i]-'a'][0]==0)
        {
            fout<<"-1";
            return 0;
        }
    }
    for(i=0;i<=27;i++)
    {
        a[i][0]=0;
    }
    for(i=1;i<=n;i++)
    {
        poz = a[s2[i]-'a'][++a[s2[i]-'a'][0]];
        start = poz+1;
        finish = n;
        query(1,1,n);
        update(1,1,n);
    }
    fout<<sol;

    return 0;
}
