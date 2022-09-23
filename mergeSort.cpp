#include<iostream>
using namespace std;
void merge(int *arr,int *b,int *c,int s ,int e){
    int i=s;
    int mid=(s+e)/2;
    int j=mid+1;
    int k=s;
    while (i<=mid && j<=e)
    {
        if(b[i]<c[j]){
            arr[k++]=b[i++];
        }
        else{
            arr[k++]=c[j++];
        }
    
    }
    while(i<=mid){
        arr[k++]=b[i++];
    }
    while(j<=e){
        arr[k++]=c[j++];
    }
    

}
void mergeSort(int *arr,int s,int e){ 
//base case
    if(s>=e){
        return;
    }
    // follow 3 steps
    //1. Divude
    int b[1000];int c[1000];
    int mid=(s+e)/2;
    // first array start to mid;
    for(int i=0;i<=mid;i++){
        b[i]=arr[i];
    }
    // 2nd array mid to end;
    for(int i=mid+1;i<=e;i++){
        c[i]=arr[i];
    }
    // Sort
    mergeSort(b,s,mid);
    mergeSort(c,mid+1,e);

    // merge the 2 parts
    merge(arr,b,c,s,e);
}
int main(){
    // int arr[]={5,6,1,2,4,0};
    int arr[]={8,7,6,5,1,2,3,4};
    int n=sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}