//https://leetcode.com/problems/vowels-of-all-substrings/solutions/
class Solution {
public:
    long long countVowels(string word) {
        map<char, int > mp;
        mp['a'] = 1;
        mp['e'] = 1;
        mp['i'] = 1;
        mp['o'] = 1;
        mp['u'] = 1;
        long long int sum = 0;
        for(int i=0;i<word.size();i++) {
            if(mp[word[i]] == 1) {
                sum=sum+1;
                sum = sum+word.size()-1-i;
                if(i!=0) {
                    sum=sum+i;
                    sum = sum+(i*(word.size()-1-i));
                }
                
            }
        }
        return sum;
    }
};
