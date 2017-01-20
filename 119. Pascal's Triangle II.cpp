class Solution {
public:
    vector<int> getRow(int n) {

        vector<int> result;

        result.push_back(1);

        if(n == 0)
            return result;

        for(int i = 0; i<n; ++i) {

            int oldcopy = result[0];

            int j = 1;

            while(j < result.size()) {

                int temp = result[j];
                result[j] = result[j] + oldcopy;
                oldcopy = temp;
                j++;

            }

            result.push_back(oldcopy);

        }

        return result;
    }
};
