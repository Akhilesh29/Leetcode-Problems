class Solution {
public:
    
    int solve(map<pair<int,int>,int>& maxi,int i,int j,vector<vector<int>>&dp){
        if(i == j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k < j;k++){
            
            ans=min(ans,maxi[{i,k}]*maxi[{k+1,j}] + solve(maxi,i,k,dp) + solve(maxi,k+1,j,dp));
        }
        dp[i][j]= ans;
        return dp[i][j];
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        map<pair<int,int>,int>maxi;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i < n;i++){
            maxi[{i,i}]=arr[i];
            for(int j=i+1; j < n;j++){
                maxi[{i,j}]=max(arr[j],maxi[{i,j-1}]);
            }
        }
        return solve(maxi,0,n-1,dp);
    }
};