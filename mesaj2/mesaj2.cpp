#include<fstream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
ifstream cin("mesaj2.in");
ofstream cout("mesaj2.out");
string code,word;
int n,length,First[1010][128],J[1010],i,j;
int main()
{
    getline(cin,code);
    cin>>n;
    length=code.length();
    for(i=1;i<=127;i++)
    {
        for(j=length-1;j>=0;j--)
        {
            First[length][i]=L;
            if(code[j]==i)
                First[j][i]=i;
            else
                First[j][i]=L;
        }
    }
    for(i=0;i<=L;i++)
        J[i]=L;
    for(i=1;i<=n;i++)
    {
        getline(cin,word);
        for(j=0;j<L;j++)
        {
            for
        }
    }
}

