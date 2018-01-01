#include<fstream>
using namespace std;
ifstream cin("harddp.in");
ofstream cout("harddp.out");
char A[1001];
int T,N,nr1,nr0;
string s1,s0;
int main()
{
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        nr1=nr0=0;
        cin>>N;
        cin>>A;
        for(int i=0;i<N;i++)
        {
            A[i]=='1'? nr1+=1: nr0+=1;
            s1+='1';
            s0+='0';
        }
        if(nr1>=nr0)
            cout<<s0;
        else
            cout<<s1;
        cout<<"\n";
    }
}
