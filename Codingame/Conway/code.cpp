#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int R,N,i,nr,j;
string S;
string F;
string E;
int v[]={0,0,0,0};
int main()
{
    cin>>R>>N;
    if(N==1)
    {
        cout<<R;
        return 0;
    }
    if(R!=1)
    {
        while(R)
        {
            S+=R%10+'0';
            R/=10;
        }
        S+=" 1";
        reverse(S.begin(),S.end());
        if(N==2)
        {
            cout<<S;
            return 0;
        }
        if(N==3)
        {
            cout<<"1 1 "<<S;
            return 0;
        }
        E=S;
        S="";
        S+="1 1 ";
        S+=E;
        for(i=4;i<=N;i++)
        {
            F=S;
            S="";
            char a=F[0];
            memset(v,0,sizeof(v));
            for(j=0;F[j]!=0;j+=2)
            {
                if(F[j]=='1' and F[j+3]!=' ')
                {
                    if(a=='1')
                        S+=(v[a-'0']+'0'+1);
                    else
                        S+=(v[a-'0']+'0');
                    S+=" ";
                    S+=a;
                    S+=" ";
                    v[a-'0']=0;
                    a=F[j];
                    break;
                }
                if(F[j]!=a)
                {
                    S+=(v[a-'0']+'0');
                    S+=" ";
                    S+=a;
                    S+=" ";
                    v[a-'0']=0;
                    v[F[j]-48]++;
                    a=F[j];
                }
                else
                {
                    v[F[j]-'0']++;
                }
            }
            S+=E;
        }
        cout<<S;
        return 0;
    }
    R=1;
    if(N==1)
    {
        cout<<R;
        return 0;
    }
    if(N==2)
    {
        cout<<"1 1";
        return 0;
    }
    S="1 1";
    for(i=3;i<=N;i++)
    {
        F=S;
        S="";
        char a=F[0];
        memset(v,0,sizeof(v));
        for(j=0;j<F.length();j+=2)
        {
            if(F[j]!=a)
            {
                S+=(v[a-'0']+'0');
                S+=" ";
                S+=a;
                S+=" ";
                v[a-'0']=0;
                v[F[j]-48]++;
                a=F[j];
            }
            else
            {
                v[F[j]-'0']++;
            }
        }
        S+=(v[1]+48);
        S+=" 1";
    }
    cout<<S;
}
