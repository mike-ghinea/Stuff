#include<fstream>
using namespace std;
ifstream cin("palc.in");
ofstream cout("palc.out");
int i,j,k,m,ok,Min;
char s,v[201];
int main()
{
    while(cin>>s)
        {
            k++;
            v[k]=s;
        }
    for(i=1;i<=k;i++)
    {
       v[0]=v[k];
       for(m=k;m>=0;m--)
       {
           v[m+1]=v[m];
       }
        for(m=1;m<=k/2;m++)
       {
        if(v[m]==v[k+1-m])
            ok=1;
        else
        {
            ok=0;break;
        }
        }
         if(ok==1)
         {
             Min=i;break;
         }
    }
    if(Min>k/2&&ok==1)
        cout<<k-Min;
    else if(Min<=k/2&&ok==1)
        cout<<Min;
    else if(ok==0)
        cout<<-1;
    return 0;
 }
