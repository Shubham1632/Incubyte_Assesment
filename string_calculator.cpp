#include <bits/stdc++.h>
using namespace std;

class StringCalculator
{
private:
    bool isneg = false;
    vector<int> neg;

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
                if (temp > 1000)
                    continue;
                ans += temp;
            }

            if (numbers[i] <= 'z' && numbers[i] >= 'a')
            {
                ans += numbers[i] - '`';
            }

            if (numbers[i] == '-' && isdigit(numbers[++i]))
            {
                int temp = 0;
                isneg = true;
                while (isdigit(numbers[i]))
                {
                    temp = temp * 10;
                    temp += (numbers[i] - '0');
                    i++;
                }
                temp -= 2 * temp;
                neg.push_back(temp);
                while (numbers[i + 1] != '-' && i < numbers.size())
                {
                    i++;
                }
            }
        }

        if (isneg)
        {
            cout << "Negatives are not allowed ";
            for (int i = 0; i < neg.size() - 1; i++)
            {
                cout << neg[i] << ",";
            }
            isneg = false;
            int lastel = neg[neg.size() - 1];
            neg.clear();
            return lastel;
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
