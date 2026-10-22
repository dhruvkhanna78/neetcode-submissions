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
        priority_queue<int, vector<int>, greater<int>> room;

        for(int i = 0 ; i < n ; i++){
            int s = intervals[i].start;
            int e = intervals[i].end;
            if(room.empty()){
                room.push(e);
            }
            else{
                bool found = false;
                for(int j = 0 ; j < room.size() ; j++){
                    if(s >= room.top()){
                        room.pop();
                        room.push(e);
                        found = true;
                        break;
                    }
                }

                if(!found){
                    room.push(e);
                }
            }
        }
        return room.size();
    }
};
