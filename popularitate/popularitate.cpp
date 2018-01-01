#include<fstream>
using namespace std;
ifstream cin("popularitate.in");
ofstream cout("popularitate.out");
int n,i=2,x,j,d,n1,v[20],v1[20],p,q=1,ne,nb,l=2,ion[100000000],Max=-1;
int main()
{
    cin>>d>>n;
    p=d;
    while(i*i<=d)
    {
        ne=0;
        while(p%i==0)
        {
             ne++;
             p=p/i;
        }
        if(ne!=0)
        {v[q]=ne;
        v1[q]=i;
        q++;}
        if(p==1)
            break;
        if(i==2)
             i=3;
        else
        i+=2;
    }
    if(p!=1)
    {v[q]=1;
    v1[q]=p;}
    q=0;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        for(j=1;j<=x;j++)
        {
            cin>>nb;
            p=nb;
            l=2;
            while(l*l<=nb)
            {
                ne=0;
                if(p%l==0)
                {
                    ne++;
                    p=p/l;
                }
                if(ne!=0)
                ion[l]+=ne;
                if(p==1)
                break;
                if(l==2)
                l=3;
                else
                l+=2;
            }
            if(p!=1)
            ion[p]++;
        }

    }
}


