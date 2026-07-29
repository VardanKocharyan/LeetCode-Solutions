class MyCalendar {
private:
    std::set<std::pair<int, int>> inter;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto it = 
            inter.upper_bound(
                {startTime, std::numeric_limits<int>::max()}
            );

        if (it != inter.end()) {
            if (it->first < endTime) return false;
        }

        if (it != inter.begin()) {
            if (std::prev(it)->second > startTime) return false;
        }

        inter.insert(it, {startTime, endTime});

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
