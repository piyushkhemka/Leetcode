class RandomizedSet {
public:

    unordered_map<int, int> m;
    vector<int> nums;

    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(int(time(0)));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {

        if(m.find(val)!=m.end())
            return false;

        m[val] = nums.size();
        nums.push_back(val);
        return true;


    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {

        if(m.find(val) == m.end())
            return false;

        int last = nums.back();
        int index = m[val];
        m[last] = index;
        nums[index] = last;
        nums.pop_back();

        m.erase(val);

        return true;

    }

    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
