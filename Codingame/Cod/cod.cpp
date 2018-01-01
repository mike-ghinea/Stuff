#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
string Mesaj;
string COD;
string LIT;
string ChNo;
int main()
{
    int i,x,n;
    getline(cin,Mesaj);
    n=Mesaj.length();
    for(i=0;i<n;i++)
    {
        x=(int)Mesaj[i];
        while(x)
        {
            if(x%2==1)
                LIT=LIT+'1';
            else
                LIT=LIT+'0';
            x/=2;
        }
        if(LIT.length()<7)
            LIT+='0';
        reverse(LIT.begin(),LIT.end());
        COD+=LIT;
        LIT="";
    }
    n=COD.length();
    for(i=0;i<n;i++)
    {
        if(COD[i]=='1')
        {
            ChNo+="0 ";
            while(COD[i]=='1')
            {
                ChNo+='0';
                i++;
            }
            i--;
            ChNo+=' ';
        }
        if(COD[i]=='0')
        {
            ChNo+="00 ";
            while(COD[i]=='0')
            {
                ChNo+='0';
                i++;
            }
            i--;
            ChNo+=' ';
        }
    }
    cout<<ChNo<<endl;
}
