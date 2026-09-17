#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string sentence;

    cout << "Enter a sentence:\n";
    getline(cin, sentence);

    //this line makes a sentence into  different word.
    stringstream ss(sentence);//ss is  stringstream object and sentence is variable we pass inside this.
    
    //whatever word is that is stored in this variable.
    string word;
    string longest = "";

    while (ss >> word) {
        if (word.length() > longest.length()) {
            longest = word;
        }
    }

    cout << "Longest word: " << longest << endl;
    cout << "Length: " << longest.length();

    return 0;
}