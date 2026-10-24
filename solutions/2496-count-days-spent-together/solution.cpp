class Solution {
public:
    int32_t calculateDay(
        const std::string& day, 
        const std::vector<int32_t>& prefix
    ) {
        int32_t m = stoi(day.substr(0, 2));
        int32_t d = stoi(day.substr(3));
        return prefix[m - 1] + d;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        std::vector<int32_t> dates({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
        
        std::vector<int32_t> prefix(1, 0);
        for (const int32_t date : dates) 
            prefix.emplace_back(prefix.back() + date);

        int32_t AliseStart = calculateDay(arriveAlice, prefix);
        int32_t AliseFinish = calculateDay(leaveAlice, prefix);
        int32_t BobStart = calculateDay(arriveBob, prefix);
        int32_t BobFinish = calculateDay(leaveBob, prefix);

        return std::max(
            0,
            std::min(AliseFinish, BobFinish) - std::max(AliseStart, BobStart) + 1
        );
    }
};
