//****************************************************************************************************
//     File:               Assignment6-1.cpp
// 
//     Student:            Anna Sargsyan
// 
//     Assignment:         Program #6 Part I
// 
//     Course Name:        Programming II
// 
//     Course Number:      COSC 1560-01
// 
//     Due:                October 9, 2023
//
//     This program asks the user to write a sentence and then counts how many words are there.
//     
//****************************************************************************************************

#include <iostream>
#include <cstring>

using namespace std;

int numberWords(const char* words, int size);

int main()
{
    const int SIZE = 60;
    char* words = new char[SIZE];

    for (int i = 0; i < 2; i++)
    {
        cout << "Enter a line of words ended by '.' " << endl;
        cin.getline(words, SIZE);

        int length = strlen(words);

        if (length > 0)
        {
            int wordCount = numberWords(words, length);
            cout << "Number of words in the entered line: " << wordCount 
                << endl;
        }
        else
        {
            cout << "No words were found." << endl;
        }

    }

    delete[] words;

    return 0;

}

//****************************************************************************************************

int numberWords(const char* words, int size)
{
    int wordCount = 0;
    bool inWord = false;

    for (int i = 0; i < size; i++)
    {
        if (words[i] == ' ' || words[i] == ',')
        {
            inWord = false;
        }
        else
        {
            if (!inWord)
            {
                wordCount++;
                inWord = true;
            }
        }
    }

    return wordCount;
}

//****************************************************************************************************
/*
Enter a line of words ended by '.'
I love this world.
Number of words in the entered line : 4
Enter a line of words ended by '.'
I love and miss my family.
Number of words in the entered line : 6
*/
