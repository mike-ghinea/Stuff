#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string S,a;
    int k,i,j;
    getline(cin, S);
    for(i=0;i<S.length();i++)
    {
        k=0;
        while(S[i]>='0' and S[i]<='9')
        {

            k+=S[i]-48;
            i++;
            k*=10;
        }
        i--;
        k/=10;
        a="";
        while(S[i]>'9' and i!=S.length())
        {
            a+=S[i];
            i++;
        }
        i--;
        for(j=1;j<=k;j++)
            cout<<a;
    }
}
