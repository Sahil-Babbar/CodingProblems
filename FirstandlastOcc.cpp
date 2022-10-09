#include<iostream>
using namespace std;
int firstOcc(int *arr,int n,int target){
    int l=0;
    int r=n-1;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==target){
            ans=mid;
            r=mid-1;
        }
        else if(arr[mid]<target){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}
int lastOcc(int *arr,int n,int target){
    int l=0;
    int r=n-1;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==target){
            ans=mid;
            l=mid+1;
        }
        else if(arr[mid]<target){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}
int main(){
    int arr[]={5,7,7,8,8,10};
    int target=8;
    int n=sizeof(arr)/sizeof(int);
    cout<<firstOcc(arr,n,target)<<endl;
    cout<<lastOcc(arr,n,target);
}