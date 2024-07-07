// Top K Frequent Elements 
// https://leetcode.com/problems/top-k-frequent-elements/description/

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> check ;
        for(int i = 0 ; i<nums.size() ; i++){
            check[nums[i]]++ ;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for(auto &it : check){
            buckets[it.second].push_back(it.first);
        }
        vector<int> ans ;
        for(int i = nums.size() ; i>=0 ; i--){
            if(ans.size() >= k){
                break ;
            }
            if(!buckets[i].empty()){
                for(int j = 0 ; j<buckets[i].size() ; j++){
                    ans.push_back(buckets[i][j]);
                }
            }
        }
        return ans ;
    }