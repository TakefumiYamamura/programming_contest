#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


// struct Interval {
// 	int start;
// 	int end;
// 	Interval() : start(0), end(0) {}
// 	Interval(int s, int e) : start(s), end(e) {}
// };

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		for (int i = 0; i < intervals.size(); ++i)
		{
			Interval tmp = intervals[i];
			if(newInterval.start < tmp.start && newInterval.end < tmp.start) continue;
			if(tmp.end < newInterval.start && tmp.end < newInterval.end) continue;
			newInterval.start = min(tmp.start, newInterval.start);
			newInterval.end = max(tmp.end, newInterval.end);
			intervals.erase(intervals.begin() + i);
			i--;
		}
		if(intervals.size() == 0){
			intervals.push_back(newInterval);
			return intervals;
		}
		int lastEnd = -1 * INT_MAX;
		for (int i = 0; i <= intervals.size(); ++i)
		{
			if(i == intervals.size()){
				if(lastEnd < newInterval.start) intervals.push_back(newInterval);
			}
			if(lastEnd < newInterval.start && newInterval.end < intervals[i].start){
				intervals.insert(intervals.begin() + i, newInterval);
				break;
			}
			lastEnd = intervals[i].end;
		}

		return intervals;

	}
};
