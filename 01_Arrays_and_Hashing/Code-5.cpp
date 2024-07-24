// Top K Frequent Elements 
// https://leetcode.com/problems/top-k-frequent-elements/description/

// Algorithm 
// 1. Create a Hashmap to store Elements -> Frequencies
// 2. Traverse the Array and store the frequencies  

// 3. Create a 2D Vector of Rows n+1 to store the Elements occuring at same Frequency 
// 4. Traverse the Hashmap and add the Elements to their Frequencies 

// 5. Create an Ans Vector 
// 6. Traverse through the 2D Vector in Reverse Order
// 7. If the size of Ans vector >= K -> Break Loop
// 8. Add the Elements in a particular frequency to the Ans Vector

// 9. Return Ans

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> check;
        for (int i = 0; i < nums.size(); i++) {
            check[nums[i]]++;
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& pair : check) {
            buckets[pair.second].push_back(pair.first);
        }
        vector<int> ans;
        for (int i = nums.size(); i >= 0; i--) {
            if (ans.size() >= k) {
                break;
            }
            for (int j = 0; j < buckets[i].size(); j++) {
                ans.push_back(buckets[i][j]);
            }
        }
        return ans;
    }

// Algorithm 
// 1. Create a Hashmap to store Elements -> Frequencies
// 2. Traverse the Array and store the frequencies 

// 3. Create a Min Heap of Pairs (Frequencies -> Elements)
// 4. Traverse the Hashmap and store the Min Heap Pairs (Frequencies -> Elements)
// 5. If at any time the size of Min Heap goes above K , we pop

// 6. Create a Vector Ans 
// 7. While Min Heap is not Empty we add the Elements to our Ans and pop

// 8. Return Ans

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> check;
        for (int i = 0; i < nums.size(); i++) {
            check[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;
        for (auto &pair : check) {
            pq.push({pair.second, pair.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }