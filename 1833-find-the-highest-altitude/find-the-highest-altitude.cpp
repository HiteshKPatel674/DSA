class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int n=gain.size();
        vector<int>altitudes(n+1,0);

        for(int i=1;i<altitudes.size();i++)
        {
            altitudes[i]=gain[i-1]+altitudes[i-1];
        }

        int largest=*max_element(altitudes.begin(),altitudes.end());
        return largest;
        
    }
};