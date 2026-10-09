class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];
        vector<int> ans(n);
       
        for(int i = 1 ; i < n ; i++){
            prefix[i] = prefix[i - 1] * nums[i];
        }

        for(int j = n - 2 ; j >= 0 ; j--){
            suffix[j] = suffix[j + 1] * nums[j];
        }

        for(int i = 0 ; i < n ; i++){
            if(i == 0){
                ans[i] = suffix[i + 1];
                continue;
            }

            if(i == n - 1){
                ans[i] = prefix[n - 2];
                continue;
            }

            ans[i] = prefix[i - 1] * suffix[i + 1];
        }
        return ans;
    }
};
