#include<iostream>
using namespace std;
int BinarySearch(int arr[4][4],int m,int n,int target){
    int r=0;
        int c=n-1;
        bool elementfound=false;
        while (r<m and c>=0)
        {
            if(arr[r][c]==target){
                elementfound=true;
                break;
            }
            else if(arr[r][c]<target){
                r++;
            }
            else{
                c--;
            }
        }
        return elementfound;
    
}
int main(){
    int arr[4][4]={
    {1,3,5,7},
    {10,11,16,20},
    {23,30,34,60},
    {62,63,64,68}
    };
    if(BinarySearch(arr,4,4,11)){
        cout<<"Element Found";
    }
    else{
        cout<<"Element Not found";
    }
}