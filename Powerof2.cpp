#include<iostream>
bool powerof2(int n){
    if(n<1){
        return false;
    }
    while(n%2==0){
        n=n/2;
    }
    return n==1;
}
// 2 method----------------------
 bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        return ((n&(n-1))==0);
    }
using namespace std;
int main(){
    int n;
    cin>> n;
    if(powerof2(n)){
        cout<<"true";
    }
    else{
        
        cout<<"false";
    }

    //----2nd way----
    if(isPowerOfTwo(n)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}