#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 43;

char* toPigLatin(char* word);
bool isVowel(char ch);

int main()
{
    // creation of 5 character strings, each length MAX
    char word[5][MAX]{ "This", "eat" , "inward", "outward", "upward" };



    int i;				// loop counter

    //cout << "Input 5 words: ";
    //for (i = 0; i < 5; i++)
    //    cin >> word[i];

    cout << "\nPig Latin version of the 5 words:\n";
    for (i = 0; i < 3; i++) // coult put as 5 and comment the cout below
    {
        toPigLatin(word[i]);
        cout << word[i] << ' ';
    }
    // Note that the above outputs illustrate that the original
    //  string itself has been converted.  The outputs below illustrate
    //  that a pointer to this string is also being returned from the 
    //  function.

    cout << toPigLatin(word[3]) << ' '
        << toPigLatin(word[4]) << '\n';

    return 0;
}

// Write your definition of the toPigLatin function here
// - ay added to the end of the word
char* toPigLatin(char* word) {
    if (isVowel(word[0])) {
        return strncat(word, "-ay", 3);
    }
    else {
        int i = 1;
        while (word[i] != '\0' && !isVowel(word[i])) { // not reach the end of string increment i.
            ++i;
        }
        char temp[MAX] = { '\0' };
        strncat(temp, &word[i], strlen(word) - i);
        strncat(temp, "-", 1);
        strncat(temp, word, i);
        strncat(temp, "ay", 2);
        strncpy(word, temp, strlen(temp));
    }
    return word;
}

bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}