#include<iostream>
using namespace std;
string ceaserCypher(string s,int num){
    string ans="";
    for(int i=0;i<s.length();i++){
        // if the char is in uppercase..
        if(isupper(s[i]))
            ans+=char(int(s[i]+num-65) % 26+65);
        else if(islower(s[i]))
            ans+=char(int(s[i]+num-97) % 26+97);
        else
            ans+=s[i];  

    }
    return ans;
}
int main(){
    string s;
    int num;
    cout<<"enter the string"<<endl;
    getline(cin, s);
    cout<<"enter the number"<<endl;
    cin>>num;
    cout<< ceaserCypher(s,num);
}