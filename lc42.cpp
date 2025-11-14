class Solution {
public:
    int max11(vector<int>& arr) {
        int maxIdx = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[maxIdx]) maxIdx = i; }
        return maxIdx;}
        int trap(vector<int>& h) {
      
    int maxIndex = max11(h);
        int sum = 0;
    int leftMax = h[0];
        for (int i = 1; i < maxIndex; i++) {
            if (h[i] >= leftMax) leftMax = h[i];
            else sum += leftMax - h[i];}
    int rightMax = h[h.size() - 1];
        for (int i = h.size() - 2; i > maxIndex; i--) {
            if (h[i] >= rightMax) rightMax = h[i];
            else sum += rightMax - h[i];
        }return sum;
    }
};
