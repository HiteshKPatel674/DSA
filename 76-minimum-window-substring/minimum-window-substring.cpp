class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int>freq_need;
        int n=s.size();
        int m=t.size();

        for(int i=0;i<m;i++)
        {
            freq_need[t[i]]++;
        }
      
        int formed=0;//number of unique characters whose required frequency has been satisfied
        int required=freq_need.size();

        int left=0;
        int right=0;
        unordered_map<char,int>window;
        int min_size=INT_MAX;
        pair<int,int>indices;//<start,end>

        while(right<n)
        {
            char c=s[right];
           
            // window[c]++;

            // if(window[c]==freq_need[c])
            //     formed++;

            //Suppose c==D wihc is not in t..Therefore freq_need map will create the key D and initilize the value of the D as 0....therefore it will create problem in future when we 
            //decremenet the  c using window[left]..it can match to the freq_need[D]..therefore changing the value of formed variable.

            if(freq_need.count(c))
            {   
                window[c]++;
                if(window[c]==freq_need[c]) formed++;
            }
            
            while(required==formed)
            {
                if(min_size>(right-left+1))
                {
                    min_size=right-left+1;
                    indices.first=left;
                    indices.second=right;
                }

                //Is s[left] present in freq_need?
                char ch=s[left];

                if(freq_need.count(ch))
                {
                    // If removing this character breaks the requirement,
                    // decrease formed BEFORE decrementing its frequency.
                    if (window[ch] == freq_need[ch])
                        formed--;
                

                window[s[left]]--;

                if(window[ch]==0) window.erase(ch);
                }

                left++;
            }
            
            right++;

        }

        if(min_size==INT_MAX) return "";

        string ans="";
        ans=s.substr(indices.first,indices.second-indices.first+1);

        return ans;


        
    }
};