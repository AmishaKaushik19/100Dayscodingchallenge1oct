// 821 shortest-distance-to-a-character

class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        vector<int> res(s.length());
        int lastC = -1;
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == c)
            {
                res[i] = 0;
                for (int j = lastC + 1; j < i; j++)
                {
                    res[j] = (lastC == -1 ? i - j : min(i - j, j - lastC));
                }
                lastC = i;
            }
            else
                res[i] = i - lastC;
        }
        return res;
    }
};