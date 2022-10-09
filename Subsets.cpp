#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int>& nums,vector<int>output,int i,vector<vector<int>>& ans){
    // base case
    if(i>=nums.size()){
        ans.push_back(output);
        return;
    }

    // recursive case
        // 1st case exclude the number
        solve(nums,output,i+1,ans);

        // 2nd case include the number
        output.push_back(nums[i]);
        solve(nums,output,i+1,ans);
}
 vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>>ans;
    vector<int>output;
    int index=0;
    solve(nums,output,index,ans);
    return ans;
}
int main(){
    int n=3;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int no;
        cin>> no;
        nums.push_back(no);
    }
    vector<vector<int>>ans=subsets(nums);
     for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout <<"{"<< ans[i][j] << "}";
        }    
        cout << endl;
    }
    
}