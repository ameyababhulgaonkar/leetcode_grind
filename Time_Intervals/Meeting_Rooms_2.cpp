class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        vector<int> startTimes;
        vector<int> endTimes;
        for(auto& interval : intervals)
        {
            startTimes.push_back(interval.start);
            endTimes.push_back(interval.end);
        }

        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int sItr = 0;
        int eItr = 0;
        int res = INT_MIN;
        int rooms = 0;

        while(sItr < startTimes.size())
        {
            if(startTimes[sItr] < endTimes[eItr])
            {
                ++rooms;
                ++sItr;
            }
            else{
                ++eItr;
                --rooms;
            }

            res = max(res, rooms);
        }

        return res;
    }
};
