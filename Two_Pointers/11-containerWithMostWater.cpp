class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), ans = 0;
        int l = 0, r = n-1;
        while (l < r) {
            int water = min(height[l], height[r]) * (r-l);
            ans = max(ans, water);
            if (height[l] < height[r])l++;
            else r--;
        }
        return ans;
    }
};