class Solution {
public:
    int minMoves(vector<int>& nums) {

        int ans = 0;
        int mine = INT_MAX;
        int sum = 0;
        for(auto i:nums) {

            mine = min(mine,i);
            sum += i;
        }

        ans = sum - nums.size()*mine;
        return ans;
    }
};


/*

Addding 1 to n - 1 elements is the same is subtracting 1 from one element, w.r.t goal of making the elements in the array equal.
So, best way to do this is make all the elements in the array equal to the min element.
sum(array) - n * minimum

*/
