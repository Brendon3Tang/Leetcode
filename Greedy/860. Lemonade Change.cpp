class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        
        for(int i = 0; i < bills.size(); i++)
        {
            if(bills[i] == 5)
                five++;
            else if(bills[i] == 10)
            {
                if(five == 0)
                    return false;
                else
                {
                    ten++;
                    five--;
                }
            }
            else
            {
                if(ten >= 1 && five >= 1)
                {
                    ten--;
                    five--;
                }
                else if(ten == 0 && five >= 3)
                    five = five - 3;
                else
                    return false;
            }
        }
        return true;
    }
};