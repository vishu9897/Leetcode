class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> vc(numRows);
        // cout<<"yes"<<endl;
        if(numRows==1) return s;
        int index=0,i=0,n=s.size();
        bool flag;
        while(i<n)
        {
            // cout<<i<<" "<<index<<" flag"<<endl;
            if(index==0)
            {
                flag=true;
            }
            if(index==numRows-1)
            {
                flag=false;
            }
            vc[index].push_back(s[i++]);
            if(flag==true)
            {
                index++;
            }
            else{
                index--;
            }
        }
        string res="";
        for(auto x:vc)
        {
            res=res+x;
        }
        return res;

    }
};