#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

// �ˬd����O�_���|�Ӧr��
bool isFourLetterWord(const std::string& word) {
    return (word.length() == 4);
}

// �����|�Ӧr������r
string replaceFourLetterWords(const std::string& text) {
    stringstream ss(text);
    string word;
    string result;

    while (ss >> word) {        //�q�y�l��Ū��r�s��word�ܼƤ�(�|���L�ť�)
        string punctuation;

        // �ˬd��������O�_�����I�Ÿ�
        if (!isalpha(word.back())) {
            punctuation = word.back();
            word = word.substr(0, word.length() - 1);   //��substr�R���r�ꪺ�̫�@�Ӧr��
        }

        if (isFourLetterWord(word)) {
            if (isupper(word[0])) {
                result = result + "Love";
            }
            else {
                result = result + "love";
            }
        }
        else {
            result = result + word;
        }

        result = result + punctuation + " ";
    }

    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

int main(void) {
    string input_word;      //��J���y�l
    string output_word;     //��X���y�l

    //Ū��quit�h�X
    cout << "Input a string �]input 'quit' to exit�^: ";
    while (true) {
        getline(cin, input_word);

        if (input_word == "quit") break;

        output_word = replaceFourLetterWords(input_word);
        cout << output_word << endl;

        cout << "Input other string�]or input 'quit' exit�^:" << endl;
    }

    system("pause");
    return 0;
}