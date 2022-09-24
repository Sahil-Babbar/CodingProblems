#include<iostream>
#include<string.h>
using namespace std;
void rotateString(char*a,int x){
    // move every character  n positions ahead
    int len=strlen(a);
    x=x%len;
    int i=len-1;
    while(i>=0){
        a[i+x]=a[i];
        i--;
    }
    cout<<"After shifting by X char "<<a<<endl;
    int j=len;
    i=0;
    while(i<x){
        a[i]=a[j];
        i++;
        j++;
    }
    a[len]='\0';
    cout<<"After rotation "<<a;
}
int main(){
    char a[100]="hello";
    int x=3; // rotate the string 5 times
    rotateString(a,x);
}