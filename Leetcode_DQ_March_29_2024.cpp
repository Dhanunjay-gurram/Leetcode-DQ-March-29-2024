class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        //Finding max_element
        int maxElement = *max_element(nums.begin(), nums.end());

        //Required Variables
        long long ans = 0;
        int  left = 0;
        int right = 0;
        int count = 0;


        while(right<nums.size()) {
            //Counts the frequency max element
            if(nums[right] == maxElement){
                count++;
            }

            //This loop increments the left index till the count is atleast k
            while(count>=k){
                //Decreases the frequency of max element since we are increasing the left index 
                if(nums[left]==maxElement){
                    count--;
                }

                left++;

                //Now sub-array is like {nums[left],nums[left+1],...,nums[right]}
                //Since the count >= k before 
                //Then even if we add elements that are right to the sub array ,the count remains atleast k 
                //Therefore we are adding all the sub arrays comprising of right elements including the terminating with nums[right].
                ans += nums.size()-right;
            }
            right++;
        }
        return ans;
    }
};