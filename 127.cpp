class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        set<string> st;
        for (string str : wordList)
        {
            st.insert(str);
        }
        queue<pair<string, int>> q;
        if (st.find(endWord) == st.end())
            return 0;
        q.push({beginWord, 1});
        st.erase(beginWord);
        while (!q.empty())
        {
            auto itr = q.front();
            q.pop();
            string str = itr.first;
            int len = itr.second;
            if (str == endWord)
                return len;
            for (int i = 0; i < str.length(); i++)
            {
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    string s = str;
                    s[i] = ch;
                    // cout<<str<<' ';
                    if (st.find(s) != st.end())
                    {
                        q.push({s, len + 1});
                        st.erase(s);
                    }
                }
                // cout<<'\n';
            }
        }
        return 0;
    }
};