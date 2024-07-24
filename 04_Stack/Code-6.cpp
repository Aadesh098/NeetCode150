// Car Fleet 
// https://leetcode.com/problems/car-fleet/

// Algorithm
// 1. Create a vector of pair<int,double> to store the initial positions and time to reach destination
// 2. Traverse the position array and fill the positions and time
// 3. Sort the vector by initial positions -> ascending order
// 4. Create a variable to store maximumTime so far to reach the target
// 5. Create a variable ans = 0 , to count number of fleets

// 6. Initiate a reverse loop n-1 -> 0
// 7. Check if time> maxTime , if yes -> maxTime = time , increment ans as new fleet formed

// 8. Return Ans 

int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            double time = (double) (target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.begin(), cars.end());
        double maxTime = 0.0;
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            double time = cars[i].second;
            if (time > maxTime) {
                maxTime = time;
                ans++;
            }
        }
        return ans;
    }