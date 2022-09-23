

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int maxProfit(int a[],int n){
    int minimum=a[0];
    int maxProfit=0;
    for(int i=0;i<n;i++){
        minimum=min(a[i],minimum);
        maxProfit=max(a[i]-minimum,maxProfit);
    }
    return maxProfit;
}
int main() {
//    int a[]={3,1,4,8,7,2,5};
   int a[]={7,1,5,3,6,4};
   int n=sizeof(a)/sizeof(int);
   cout<<"MAX Profit  "<<maxProfit(a,n);
}
