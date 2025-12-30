class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size()-1, result = 0;
        sort(citations.begin(), citations.end());
        for(int i = n; i >= 0; --i) {
            int h = n-i+1;
            if (citations[i] >= h) {
                result = h;
            };
        }
        return result;
    }
};