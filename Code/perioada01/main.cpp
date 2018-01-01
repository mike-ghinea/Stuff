#include <fstream>

#define dim 2000001
using namespace std;
ifstream fin("perioada01.in");
ofstream fout("perioada01.out");
int n,p,v[dim],poz[dim],i,nr,perl,per[dim],k,l,l1,j,OK;
int abs(int x)
{
    if(x>=0)
        return x;
    return -x;
}
int semn (int x)
{
    if(x>0)
        return 1;
    return -1;
}
int main()
{
    fin>>n>>p;
    fin>>poz[1];
    if(poz[1]==1)
        v[++nr]=-1;
    else
    {
        v[++nr]=poz[1]-1;
        v[++nr]=-1;
    }
    for(i=2;i<=p;i++)
    {
        fin>>poz[i];
        if(poz[i]==poz[i-1]+1)
            v[++nr]--;
        else
        {
            v[++nr]=poz[i]-poz[i-1]-1;
            v[++nr]=-1;
        }
    }
    if(poz[p]!=n)
        v[++nr]=n-poz[p];
//    for(i=1;i<=nr;i++)
//        fout<<v[i]<<' ';
    for(i=p;i>=2;i--)
    {
        if(n%i==0)
        {
            l=n/i;
            if(l<poz[1])
                continue;
            l1=l;
            j=1;
            perl=0;
            while(l1>=abs(v[j]))
            {
                per[++perl]=v[j];
                l1-=abs(v[j]);
                j++;
            }
            if(l1>0)
            {
                per[++perl]=l1* semn(v[j]);
            }
            OK=1;
            while(j<=nr&&OK==1)
            {
                for(k=1;k<=perl;k++)
                {
                    if(k==1)
                    {
                        if(v[j]-l1!=per[k])
                        {
                            OK=0;
                            break;
                        }
                    }
                    else
                    {
                        if(k==perl)
                        {
                            if(v[j]<per[k])
                            {
                                OK=0;
                                break;
                            }
                            else if(v[j]>per[k])
                                    continue;


                        }
                        else if(v[j]!=per[k])
                            {
                                OK=0;
                                break;
                            }
                    }
                    j++;
                }
            }
            if(OK==1)
            {
                fout<<l;
                return 0;
            }
        }
    }
    fout<<-1;
    return 0;
}
