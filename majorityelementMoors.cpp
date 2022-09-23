

#include <iostream>
using namespace std;
int majorityelement(int arr[],int n){
  int candidate=arr[0];
  int life=1;
  for(int i=0;i<n;i++){
      if(arr[i]==candidate){
          life++;
      }
      
      else if(life==0){
          candidate=arr[i];
          life=1;
      }
      else{
          life--;
      }
  }
  for(int i=0;i<n;i++){
      if(candidate==arr[i])
        life++;
  }
  if(life>n/2)
   return candidate;   
return -1; 
}
int main() {
    int n;
    cin>> n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   cout<< majorityelement(arr,n);
}
