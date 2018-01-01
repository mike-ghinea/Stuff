#include <iostream>
using namespace std;

int sumfactcif(int n) {
        int s=0, fact;

        while(n!=0){

            if(n%10==0)
                fact=1;
            else {
                 fact=1;
                while(n%10!=0){
                    fact=fact*n%10;
                    n=n%10-1;
                    }
                s=s+fact;
                n/=10;
            }
        }

        return s;
}
int main(){
        int z=sumfactcif(241);
        cout<<z;
        return 0;

}
