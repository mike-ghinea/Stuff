#include<fstream>
#define N 200001
using namespace std;
ifstream cin("heapuri.in");
ofstream cout("heapuri.out");
int H[N],v[N],poz[N],n,nr,nrh,i,x,cod;
void add(int nod)
{
    while(nod/2 and v[H[nod]] < v[H[nod/2]])
    {
        swap(H[nod],H[nod/2]);
        swap(poz[H[nod]],poz[H[nod/2]]);
        nod/=2;
    }
}
void remove(int nod)
{
    while(2*nod<=nrh)
    {
        int aux=2*nod;
        if(aux+1<=nrh and v[H[aux]]>v[H[aux+1]])
            aux++;
        if(v[H[aux]]<v[H[nod]])
        {
            swap(H[nod],H[aux]);
            swap(poz[H[nod]],poz[H[aux]]);
            nod=aux;
        }
        else
            break;
    }
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>cod;
        switch(cod)
        {
            case 1:
                cin>>v[++nr];
                H[++nrh]=nr;
                poz[nr]=nrh;
                add(nrh);
                break;
            case 2:
                cin>>x;
                H[poz[x]]=H[nrh];
                poz[H[nrh]]=poz[x];
                nrh--;
                remove(poz[x]);
                break;
            default:
                cout<<v[H[1]]<<"\n";
                break;
        }
    }
}

