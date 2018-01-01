#include <fstream>
#include <set>

#define dim 200002
using namespace std;
ifstream fin("heapuri.in");
ofstream fout("heapuri.out");
int v[dim],t,ot,x,n,i,heap[dim],poz[dim],y,nrh;
void up(int k)
{
    while(k/2 > 0)
    {
        if(v[heap[k/2]] > v[heap[k]])
        {
            swap(poz[heap[k/2]],poz[heap[k]]);
            swap(heap[k/2],heap[k]);
            k=k/2;
        }
        else
            break;
    }
}
void down(int k)
{
    while(2*k<=nrh)
    {
        int po=2*k;
        if(po+1<=nrh && v[heap[po]] > v[heap[po+1]])
            po=po+1;
        if(v[heap[po]]<v[heap[k]])
        {
            swap(poz[heap[po]],poz[heap[k]]);
            swap(heap[po],heap[k]);
            k=po;
        }
        else
            break;
    }
}
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>ot;
        if(ot==1)
        {
            fin>>v[++n];
            heap[++nrh]=n;
            poz[n]=nrh;
            up(nrh);
            continue;
        }
        if(ot==2)
        {
            fin>>y;
            heap[poz[y]] = heap[nrh];
            poz[heap[nrh]] = poz[y];
            nrh--;
            down(poz[y]);
            continue;
        }
        fout<<v[heap[1]]<<'\n';
    }
    return 0;
}
