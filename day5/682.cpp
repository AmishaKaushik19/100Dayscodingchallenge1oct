// 682. Baseball Game
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        vector<int> a;

        for (string s : operations)
        {
            if (s == "C")
            {
                a.pop_back();
            }
            else if (s == "D")
            {
                a.push_back(a[a.size() - 1] * 2);
            }
            else if (s == "+")
            {
                a.push_back(a[a.size() - 1] + a[a.size() - 2]);
            }
            else
            {
                a.push_back(stoi(s));
            }
        }

        int ans = 0;
        for (int i = 0; i < a.size(); i++)
            ans += a[i];

        return ans;
    }
};