class Solution {
public:
    string encode(vector<string>& strs) {
        string s = "";

        for (string& str : strs) {
            s += to_string(str.size());
            s += '#';
            s += str;
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n = s.size();
        int i = 0;

        while (i < n) {
            int start = i;

            // Find the length delimiter
            while (s[i] != '#') {
                i++;
            }

            int len = stoi(s.substr(start, i - start));

            // Move past '#'
            i++;

            // Extract exactly len characters
            string curr = s.substr(i, len);
            ans.push_back(curr);

            i += len;
        }

        return ans;
    }
};