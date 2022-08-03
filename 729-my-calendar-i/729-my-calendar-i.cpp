class MyCalendar {
public:
    map<int,int> intervals;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto [key, value] : intervals){
            if((start >= key && start < value) || (end > key && end < value)
                    || (start <= key && end >= value))
                return false;
            if(start < key && end <= key)
                break; 
        }
            intervals.insert({start, end});
            return true;    
    }
};

