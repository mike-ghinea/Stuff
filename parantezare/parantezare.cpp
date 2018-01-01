#include<fstream>
#include<cstring>
using namespace std;
ifstream cin("parantezare.in");
ofstream cout("parantezare.out");
char ch[100003];
int v[100003],s[100003],i,q,n,p,a;
int main()
{
    cin.getline(ch,100001);
    a=strlen(ch);
    for(i=0;i<=a-1;i++)
    {
        if(ch[i]=='(')
        {
            q++;
            s[q]=i;
        }
        else if(ch[i]==')')
        {
            v[s[q]]=i;
            q--;
        }
    }
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>p;
        cout<<v[p]<<" ";
    }
    return 0;
}
