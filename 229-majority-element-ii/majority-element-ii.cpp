class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> vc;
        int ele1,ele2,cnt1=0,cnt2=0;

        for(int i=0;i<nums.size();i++)
        {
            if(cnt1==0 && nums[i] != ele2)
            {
                ele1=nums[i];
                cnt1++;
            }
            else if(cnt2==0 && nums[i]!=ele1)
            {
                ele2=nums[i];
                cnt2++;
            }
            else if(nums[i]==ele1)
            {
                cnt1++;
            }
            else if(nums[i]==ele2)
            {
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(ele1==nums[i]) cnt1++;
            else if(ele2==nums[i]) cnt2++;
        }
        int n=nums.size();
        n=n/3+1;

        if(cnt1>=n) vc.push_back(ele1);
        if(cnt2>=n) vc.push_back(ele2);
        return vc;
    }
};