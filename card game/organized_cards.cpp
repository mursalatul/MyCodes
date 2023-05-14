#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> generate_cards()
{
    vector<string> numbers = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    vector<string> card = {"D", "C", "H", "S"};
    vector<string> cards;
    for (int i = 0; i < (int)card.size(); i++)
    {
        for (int j = 0; j < (int)numbers.size(); j++)
        {
            cards.push_back(card[i]+numbers[j]);
        }
    }
    return cards;
}

int main()
{
    for (string s: generate_cards())
    {
        cout << s << " ";
    }
    return 0;
}