class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m != n) return false;
        
        vector<int> sC(26, 0);
        vector<int> tC(26, 0);

        for(int i = 0 ; i < m ; i++){
            sC[s[i] - 'a']++;
        }

        for(int i = 0 ; i < n ; i++){
            tC[t[i] - 'a']++;
        }

        for(int i = 0 ; i < 26 ; i++){
            if(tC[i] != sC[i]) return false;
        }
        return true;
    }
};
