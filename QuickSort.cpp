#include<iostream>
using namespace std;
int Partition(int *a,int s,int e){
    int i=s-1;
    for(int j=s;j<e;j++){
        if(a[j]<=a[e]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
}
void QuickSort(int *arr,int s,int e){
    if(s>=e){
        return;
    }
   int indx= Partition(arr,s,e);

   QuickSort(arr,s,indx-1);
   QuickSort(arr,indx+1,e);
}
int main(){
    int arr[]={2,3,1,4,7,11,8,10,6};
    int n=sizeof(arr)/sizeof(int);
    QuickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}