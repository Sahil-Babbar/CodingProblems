#include<iostream>
using namespace std;
bool isSorted(int *arr,int n){
    //base case
    if(n==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }

    //recursive case

    return isSorted(arr+1,n-1);
}
int main(){
    int arr[]={1,2,4,5,6};
    int n=sizeof(arr)/sizeof(int);
    if(isSorted(arr,n)){
        cout<<"Sorted";
    }
    else{
        cout<<"Not Sorted";
    }
}