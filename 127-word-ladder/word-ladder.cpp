class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>set;
        for(int i=0;i<wordList.size();i++)
        {
            set.insert(wordList[i]);
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        set.erase(beginWord);

        int len=1;;

        while(!q.empty())
        {
            auto[s,l]=q.front();
            q.pop();

            if(s==endWord) return l;

            for(int i=0;i<s.size();i++)
            {   char original=s[i];
                for(int j=0;j<26;j++)
                {
                    char ch=(char)(97+j);
                    if(ch==original) continue;
                    s[i]=ch;

                    if(set.find(s)!=set.end())
                    {
                        q.push({s,l+1});
                        set.erase(s);
                    }
                }


                s[i]=original;
            }
        }
        return 0;
    }
};