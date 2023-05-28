#include <iostream>
#include <unordered_map>

using namespace std;

int word_num = 0;
string word;
unordered_map<char, char> table;

int main()
{

    table.insert({'@', 'a'});
    table.insert({'[', 'c'});
    table.insert({'!', 'i'});
    table.insert({';', 'j'});
    table.insert({'^', 'n'});
    table.insert({'0', 'o'});
    table.insert({'7', 't'});

    cin >> word_num;
    for(int i = 0; i < word_num; i++)
    {
        cin >> word;
        string result = {};
        int count = 0, size = word.size();
        for(int j = 0; j < word.size(); j++)
        {   
            if(word[j] == '\\')
            {
                if(word[j + 1] == '\\')
                {
                    if(word[j + 2] == '\'') {result += "w"; j += 2; count ++; size -= 2;}
                }
                else if(word[j + 1] == '\'')
                {
                    result += "v"; j++; count++; size--;
                }
            }
            else if(table.find(word[j]) != table.end()) {result += table[word[j]]; count++;}
            else result += word[j]; 
        }

        if(count >= (size / 2.0)) cout << "I don't understand\n";
        else cout << result << "\n";
    }
}