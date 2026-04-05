class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while(left < right) {
            int middle = left + (right - left)/2;
            long long total_hours = 0;
            for(const int& p : piles) {
                total_hours+= p/middle + (p%middle != 0);
            }
            if(total_hours <= h) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }
        return left;
    }
};
