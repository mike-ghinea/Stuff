#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
#define extension first
#define type second
using namespace std;
vector <pair <string,string> >file;
int N,Q,i,j,ok;
string a,b;
ifstream cin("mime.in");
ofstream cout("mime.out");
int main()
{
    cin>>N>>Q;
    cin.get();
    for(i=1;i<=N;i++)
    {
        cin>>a>>b;
        int n=a.length();
        for(j=0;j<n and a[j]!='.';j++)
            if(a[j]>='A' and a[j]<='Z')
                a[j]+=32;
        file.push_back(make_pair(a,b));
    }
    cin.get();
    for(i=1;i<=Q;i++)
    {
        cin>>a;
        reverse(a.begin(),a.end());
        int n=a.length();
        b="";
        for(j=0;j<n and a[j]!='.';j++)
        {
            if(a[j]>='A' and a[j]<='Z')
                b+=a[j]+32;
            else
                b+=a[j];
        }
        reverse(b.begin(),b.end());
        ok=1;
        for(j=0;j<file.size();j++)
        {
            if(b==file[j].extension)
            {
                cout<<file[j].type+'\n';
                ok=0;
            }
        }
        if(ok==1)
            cout<<"UNKNOWN\n";
    }
    return 0;
}
