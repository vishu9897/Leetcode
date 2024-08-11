class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int ele=nums[0],cnt=0;
      for(auto x: nums)
      {
          if(ele==x) cnt++;
          else cnt--;
          if(cnt==0)
          {
              ele=x;
              cnt++;
          }
          
          cout<<x<<" "<<cnt<<" "<<ele<<endl;
      }
      return ele;   
    }
};