#include <bits/stdc++.h>
using namespace std;

class StringCalculator
{
public:
    int addString(string numbers)
    {
        int ans = 0;
        for (char ch : numbers)
        {
            if (isdigit(ch))
            {
                ans += (ch - '0');
            }
        }
        return ans;
    }
};

int main()
{
    StringCalculator s1;

    string numbers;
    cin >> numbers;

    cout << s1.addString(numbers);

    return 0;
}