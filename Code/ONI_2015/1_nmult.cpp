// prof. Pit-Rada Vasile Ionel

#include<stdio.h>
long n,k,w,H=666013,r;
long long m,z,p,x,y,t,xx,yy,i;
char a[1000010];
int main(){
    freopen("nmult.in","r",stdin);
    freopen("nmult.out","w",stdout);
    scanf("%ld%ld%ld",&n,&k,&w);
    m=n-(k-1)*(w-1);
    xx=k; yy=m-k;
    if (xx<yy){xx=m-k; yy=k;}
    z=1;
    for (p=2;p<=m;p++){
        if (a[p]==0){
            for (i=p*p;i<=m;i=i+p)
                a[i]=1;
            x=xx; y=yy;
            t=0;
            while(x){
                t=(t+x%p+y%p)/p;
                if(t!=0) z=(z*p)%H;
                x=x/p;
                y=y/p;
            }
        }
    }
    r=z;
    if (m<k) printf("0\n");
        else printf("%ld\n",r);
    fclose(stdout);
    return 0;
}
