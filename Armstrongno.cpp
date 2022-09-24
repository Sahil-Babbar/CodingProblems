#include<iostream>
#include<cmath>
using namespace std;
int calclen(int n){
    int cnt=0;
    while(n>0){
        n=n/10;
        cnt++;
    }
    return cnt;
}
bool checkArmstrong(int n){
    int number=n;
    int len=calclen(n);
    int sum=0;
    while(n>0){
       int r=n%10;
        sum=sum+pow(r,len);
        n=n/10;
    }
    if(number==sum){
        return true;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    if(checkArmstrong(n)){
        cout<<"Armstrong number"<<endl;
    }
    else{
        cout<<"Not armstrong"<<endl;
    }
}