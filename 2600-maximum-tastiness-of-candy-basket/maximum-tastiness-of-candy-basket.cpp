class Solution {
private: 
	int check(int num,vector<int> &price){
		int low=0;
 		int candy=1;
		for(int i=0;i<price.size();i++){
			if(i!=0 && num<(price[i]-price[low])){
     			low=i;
				candy++;
			}
        }       
        return candy;
	}
public:
    int maximumTastiness(vector<int>& price, int k) {
    sort(price.begin(),price.end());
	int low=0, high = price[price.size()-1] - price[0];
	while(low<=high){
		int mid= low + (high-low)/2;
		int count=check(mid,price);
        if(count >= k)low=mid+1;
		else high=mid-1;
	}
	return low;
    }
};

