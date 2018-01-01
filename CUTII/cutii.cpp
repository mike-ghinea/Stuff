#include<fstream>
using namespace std;
ifstream cin("cutii.in");
ofstream cout("cutii.out");
int main()
{
    long long a,b,i,c,nr=0;
    cin>>a>>b;
    for(i=1;i<=b;i++)
    {
        if(b<a)
        {
            a=a-b;
            b=b*2;
            nr++;
            if(b==0 || a==0)
            break;
        }
        else if(a<=b)
        {
            b=b-a;
            a=a*2;
            nr++;
            if(b==0 || a==0)
            break;

        }
        if(i>=b && (b!=0 && a!=0))
        nr=-1;

    }
    cout<<nr;
    return 0;

}
