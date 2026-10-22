/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n <= 1) return n;

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
         return a.start < b.start;
     });
        vector<int> room;

        for(int i = 0 ; i < n ; i++){
            int s = intervals[i].start;
            int e = intervals[i].end;
            if(room.size() == 0){
                room.push_back(e);
            }
            else{
                bool found = false;
                for(int j = 0 ; j < room.size() ; j++){
                    if(s >= room[j]){
                        room[j] = e;
                        found = true;
                        break;
                    }
                }

                if(!found){
                    room.push_back(e);
                }
            }
        }
        return room.size();
    }
};
