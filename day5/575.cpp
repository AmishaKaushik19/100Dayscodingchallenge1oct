// 575. Distribute Candies
class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        set<int> s;
        for (auto it : candyType)
            s.insert(it);
        return min(s.size(), candyType.size() / 2);
    }
};