#include<fstream>
using namespace std;
ifstream cin("submultimi.in");
ofstream cout("submultimi.out");
int n,i=1,v[18];
int main()
{
    cin>>n;
    while(v[n+1]==0)
    {
        for(i=1;i<=n+1;i++)
        {
            if(v[i]==1)
            {
                v[i]=0;
            }
            else
            {
                v[i]=1;
                break;
            }
        }
        if(v[n+1]==0)
        {
            for(i=1;i<=n;i++)
                 if(v[i]==1)
                    cout<<i<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
