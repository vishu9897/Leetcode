class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int temp=-1;
        for(int i=arr.size()-1;i>=0;i--)
        {
            int x=arr[i];
            arr[i]=temp;   
            temp=max(temp,x);
        }
        return arr;
    }
};