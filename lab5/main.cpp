#include <fstream>
#include <iostream>
#include <string>

bool vowelLetter(const char letter)
{
    switch(letter)
    {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'Y':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
        return true;
    default:
        return false;
    }
}

void lastLetterIsPunctuationMark(std::string& word)
{
    auto last = word.back();
    switch(last)
    {
    case ',':
    case '.':
    case '!':
    case '?':
        word.pop_back();
        return;
    default:
        return;
    }
}

int main()
{
    std::string currentWord;
    std::ifstream ifs("E:/input.txt", std::ifstream::in);
    if (! ifs)
    {
        std::cout << "Open error" << std::endl;
        return 1;
    }

    std::cout << "Words with first vowel letter:" << std::endl;
    auto zero_word_flag = true;
    while (! ifs.eof())
    {
        ifs >> currentWord;
        if (vowelLetter(currentWord[0]))
        {
            lastLetterIsPunctuationMark(currentWord);
            std::cout << currentWord << std::endl;
            zero_word_flag = false;
        }
    }

    if (zero_word_flag)
    {
        std::cout << "No words with first vowel letter" << std::endl;
    }

	system("pause");
    return 0;
}
