class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> r_map, m_map;
        for (char ch : ransomNote) r_map[ch]++;
        for (char ch : magazine) m_map[ch]++;
        
        for (auto it = r_map.begin(); it != r_map.end(); it++)
            if (it->second > m_map[it->first]) return false;
        
        return true;
    }
};
