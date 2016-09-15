class Solution {
public:
    int maxArea(vector<int>& height) {

        int i = 0;
        int j = height.size()-1;

        int res = INT_MIN;

        while(i<j) {
            int temp = (j-i)*min(height[i], height[j]);
            res = max(res, temp);

            if(height[i]>height[j])
                j--;
            else
                i++;
        }

        return res;

    }
};
