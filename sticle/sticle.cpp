#include<fstream>
#include<math.h>
using namespace std;
ifstream cin("sticle.in");
ofstream cout("sticle.out");
int T,i,N,k;
int main()
{
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>N;
        if(N==1)
            cout<<0<<"\n";
        else if(N<=2)
            cout<<1<<"\n";
        else if(N<=4)
            cout<<2<<"\n";
        else if(N<=8)
            cout<<3<<"\n";
        else if(N<=16)
            cout<<4<<"\n";
        else if(N<=32)
            cout<<5<<"\n";
        else if(N<=64)
            cout<<6<<"\n";
        else if(N<=128)
            cout<<7<<"\n";
        else if(N<=256)
            cout<<8<<"\n";
        else if(N<=512)
            cout<<9<<"\n";
        else if(N<=1024)
            cout<<10<<"\n";
        else if(N<=2048)
            cout<<11<<"\n";
        else if(N<=4096)
            cout<<12<<"\n";
        else if(N<=8192)
            cout<<13<<"\n";
        else if(N<=16384)
            cout<<14<<"\n";
        else if(N<=32768)
            cout<<15<<"\n";
        else
            cout<<16<<"\n";
    }
}
