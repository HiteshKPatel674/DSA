class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        

        int product1 = nums[n-1] * nums[n-2] * nums[n-3]; 
        int product2 = nums[0] * nums[1] * nums[n-1];     
        
    
        return max(product1, product2);
    }
        };
//     int n=nums.size();
    //     sort(nums.begin(),nums.end());

    //     int product=1;
    //     int i=0;
    //     int j=n-1;
    //     int count=0;
    //     int count_i=0;
    //     int count_j=0;
        
    //     while(i<=j && count<3){
    //         if(nums[i]*nums[i]>nums[j]*nums[j] && count_i<2 && count_j!=2){
    //             product*=nums[i];
    //             i++;
    //             count++;
    //             count_i++;
                
                
                
    //         }
    //         else{
    //             product*=nums[j];
    //             j--;
    //             count++;
    //             count_j++;
    //         }
    //     }
    //      return product;

        
    // }
