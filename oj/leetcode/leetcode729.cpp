class MyCalendar {
public:
    vector<pair<int,int>> events;
    MyCalendar() {

        events = vector<pair<int,int>>();
        
    }
    
    bool book(int start, int end) {
        int n = events.size();
        for(pair<int,int> p : events){
            if(start >= p.second || end <= p.first){
                continue;
            }else{
                return false;
            }
        }
        events.push_back(pair<int,int>(start,end));
        return true;
    }
};
