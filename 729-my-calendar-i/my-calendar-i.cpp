class MyCalendar {
public: 
    vector<pair<int,int>>st;
    MyCalendar() {
       
    }
    
    bool book(int start, int end) {
        for(auto x:st)
        {
            int first=x.first;
            int second=x.second;

            if(start<= first && first<end) return false;
            else if(first<=start && start<second) return false;
        }
        st.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */