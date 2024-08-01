class Solution {
public:
    bool solve(vector<int> &nums,int sum,int start,int end)
    {
        if(start>=end)
        {
            if(start==end) return (sum + nums[start]) >= 0 ? true : false;
            return sum >= 0 ? true : false;
        }
        // cout<<sum<<" "<<start<<" "<<end<<endl;
        //p1 takes from front
        bool front= solve(nums,sum + nums[start]-nums[start+1],start+2,end) & solve(nums,sum + nums[start]-nums[end],start+1,end-1);
        //p1 takes from end
        bool back= solve(nums,sum+ (nums[end]-nums[start]),start+1,end-1) & solve(nums,sum+ (nums[end]-nums[end-1]),start,end-2);
        // cout<<sum<<" "<<front<<" "<<back<<endl;
        return front|back;
    }
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums,0,0,nums.size()-1);    
    }
};