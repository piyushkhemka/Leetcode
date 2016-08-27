class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int a[26] = {0};
        for(int i = 0; i<magazine.length();i++) {
            a[magazine[i]-'a']++;
        }

        for(int i = 0;i<ransomNote.length();i++) {
            a[ransomNote[i]-'a']--;
            if(a[ransomNote[i]-'a'] < 0)
                return false;
        }
        return true;
    }
};
