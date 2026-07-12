class Solution{
public:

 vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int>copy(arr.size());

        for(int i=0;i<copy.size();i++)
        {
            copy[i]=arr[i];
        }

        sort(copy.begin(),copy.end());

    // use unique() to bring all the duplicates to end
    // and get the ierator for the modified vector
    auto it= unique(copy.begin(), copy.end());

    // Use erase method  to remove all the duplicates
    // from the vector
    copy.erase(it, copy.end());


        unordered_map<int, int> rankMap;  // Map to store ranks
        for (int i = 0; i < copy.size(); i++) 
        {
        rankMap[copy[i]] = i + 1;  // Assign rank (index + 1) to each unique element
        }

        vector<int> ranking(arr.size()); 
         // Vector to store ranks

        for (int i = 0; i < arr.size(); ++i) 
       {
        ranking[i] = rankMap[arr[i]];  // arr[i] will acts a key to get the respective rank
        }
           return ranking;
}
};

    //above code is on vector and unique method and mapping..takes a longer process to execute...



// class Solution {
// public:
//     vector<int> arrayRankTransform(vector<int>& arr) {
    
//         set<int> uniqueSet(arr.begin(), arr.end());

      
//         unordered_map<int, int> rankMap;  
//         int rank = 1;
//         for (int value : uniqueSet) {
//             rankMap[value] = rank++;  
//         }

      
//         vector<int> ranking(arr.size());
//         for (int i = 0; i < arr.size(); i++) {
//             ranking[i] = rankMap[arr[i]];  // Use arr[i] as key to get rnk
//         }

//         return ranking;  
//     }
// };



        
 