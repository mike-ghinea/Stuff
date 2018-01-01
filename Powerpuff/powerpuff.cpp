#include<iostream>
using namespace std;
int n,i,x,j,a,nr,x1,x2,x3,q1,q2,q3,k;
int main()
{
    cin>>x1>>x2>>x3>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        a=x;
        while(a!=0)
        {a=a/10;nr++;}//determinam nr de cifre
        int v[nr];
        for(j=1;j<=nr;j++)
        {v[j]=x%10;x=x/10;}//creem vectorul
        for(j=1;j<=nr;j++)
        {
            q1=x1;q2=x2;q3=x3;
            int ok1=0,ok2=0,ok3=0;
            while(q1!=0)
            {
                if(q1%10!=v[j])
                ok1=1;
                if(ok1==1)
                x1=x1+q1%10;
                q1=q1/10;
            }
            if(ok1==1)
            x1=x1-v[j];


        }
    }
    cout<<x1<<" "<<x2<<" "<<x3;
    return 0;
}
