// Two Sum (Input Array Sorted)
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i + 1, j + 1};
            } else if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
        return {-1, -1};
    }