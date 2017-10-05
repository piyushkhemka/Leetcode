class Solution {

    string convertbase62(long long sum) {

        string ans = "";

        while(sum) {

            int rem = sum % 62;
            char r;

            if(rem >= 10 && rem <= 36) {
                rem = rem - 10;
                r = char(rem + int('a'));
            } else if(rem >= 37 && rem<=61) {
                rem = rem - 37;
                r = char(rem + 'A');
            } else {
                r = rem + '0';
            }


            ans = ans + r;
            sum = sum / 62;

        }
        return ans;

    }


public:

    unordered_map<string, string> m;
    time_t  timev;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {

        long sum = 0;
        for(auto c: longUrl)
            sum = sum + int(c);

        sum = sum % 256;
        long long curtime = time(&timev);
        sum = sum * curtime;

        string shorturl = convertbase62(sum);
        m[shorturl] = longUrl;
        return shorturl;

    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {

        return m[shortUrl];

    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
