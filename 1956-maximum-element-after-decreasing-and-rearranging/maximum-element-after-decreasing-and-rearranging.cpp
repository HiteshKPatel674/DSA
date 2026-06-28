class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        

        sort(arr.begin(),arr.end());
        bool one=false;

        if(arr[0]==1) one=true;
        else 
        {
            arr[0]=1;
            one=true;
        }

        int maxi=INT_MIN;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]-arr[i-1]<=1) continue;
            else
            {
                arr[i]=arr[i-1]+1;//Since we want the maximum possible value
                maxi=max(maxi,arr[i]);
            }
        }

        return (maxi!=INT_MIN) ? maxi:arr[arr.size()-1];
    }
};