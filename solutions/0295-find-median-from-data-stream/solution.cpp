class MedianFinder {
private:
    std::priority_queue<int> max;
    std::priority_queue<int,
                        std::vector<int>,
                        std::greater<int> > min;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        max.push(num);

        min.push(max.top());
        max.pop();

        if (max.size() < min.size()) {
            max.push(min.top());
            min.pop();
        }
    }
    
    double findMedian() {
        return max.size() == min.size() ? double(max.top() + min.top()) / 2 : max.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
