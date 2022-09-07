#include <bits/stdc++.h>
using namespace std;

class StringCalculator
{
public:
    int addString(string numbers)
    {
        int ans = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (isdigit(numbers[i]))
            {
                int temp = 0;
                while (numbers[i] != ',' && i < numbers.size())
                {
                    temp = temp * 10;
                    temp += (numbers[i] - '0');
                    i++;
                }
                ans += temp;
            }
        }
        return ans;
    }
};

int main()
{
    StringCalculator s1;

    vector<string> numbers = {"0", "1,2,3", "123,432,56", "1,2,a,b", "-1,2,4,d,-6", "12003,1,3", "34/n54,89"};
    for (string str : numbers)
    {
        cout << s1.addString(str) << endl;
    }

    return 0;
}
