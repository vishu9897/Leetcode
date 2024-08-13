class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        multiset<int> eventEndTime;
        int i =0;
        int ans = 0;
        int n = events.size();
        for(int d =1; d <=100000; ++d){
            //Delete expired event , example
            // Suppose 3 events are there  [1, 2] [1, 2] [1, 2]
            // at day 1 : attend 1st event and at day 2 attend 2md event , at day 3 , 3rd event is already expired, hence we need this kind of loop of loop to delete expired events
            while(!eventEndTime.empty() and *eventEndTime.begin() < d){
                eventEndTime.erase(eventEndTime.begin());
            }

            // put all candidate events whose start day is past the current day.
            
            //insert events if they can be start 
            while(i < n and events[i][0] <=d){
                eventEndTime.insert(events[i][1]);
                i++;
            }
            
            // we can attend 1 event on 1 day , thats why if condition not while
            // adn we attend earliest ending event first , suppose we have [1, 2] & [1, 3]
            // and we are on day=2, we should attend [1,2] first otherwise at d=3 this would be expired
            if(!eventEndTime.empty() and *eventEndTime.begin()>=d){
                ++ans;
                eventEndTime.erase(eventEndTime.begin());
            }
        }
        return ans;
    }
};