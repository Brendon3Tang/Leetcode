// class Solution {
// public:
//     int findMinArrowShots(vector<vector<int>>& points) {
//         vector<int> cover(2,INT_MIN);
//         sort(points.begin(),points.end());
//         int res = 0;
//         for(int i = 0; i < points.size();i++)
//         {
//             if(points[i][0] > cover[1])
//             {
//                 res++;
//                 cover[0] = points[i][0];
//                 cover[1] = points[i][1];
//             }
//             else if(points[i][1] < cover[1])
//                 cover[1] = points[i][1];
//         }
//         if(points.size() == 1)
//             return 1;
        
//         return res;
//     }
// };
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        int right_bound = points[0][1];
        sort(points.begin(),points.end());
        int res = 1;
        for(int i = 0; i < points.size();i++)
        {
            if(points[i][0] > right_bound)
            {
                res++;
                right_bound = points[i][1];
            }
            else
                right_bound = min(points[i][1], right_bound);
        }
        return res;
    }
};
