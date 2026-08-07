class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if (n % groupSize != 0)
            return false;

        unordered_map<int,int> mp;
        priority_queue<int, vector<int>, greater<int>> pq;

        // Frequency
        for (int x : hand)
        {
            if (mp.count(x) == 0)
                pq.push(x);

            mp[x]++;
        }

        while (!pq.empty())
        {
            int front = pq.top();   // Smallest available card


            for (int i = 0; i < groupSize; i++)
            {
                int card = front+i;

                if (mp[card] == 0)
                    return false;

                mp[card]--;
            }

            while (!pq.empty() && mp[pq.top()] == 0)
                pq.pop();
        }

        return true;
    }
};