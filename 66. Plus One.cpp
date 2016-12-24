class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        if(digits.empty())
            return digits;

        ++digits.back();

        if(digits.back() == 10) {

            int i = digits.size()-1;
            while(digits[i] == 10) {

                digits[i] = 0;

                if (i > 0)
                    ++digits[i-1];

                --i;

            }
        }

        if(digits[0] == 0) {
            digits.insert(digits.begin(),1);
        }

        return digits;

    }
};
