#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

// 檢查單詞是否為四個字母
bool isFourLetterWord(const std::string& word) {
    return (word.length() == 4);
}

// 替換四個字母的單字
string replaceFourLetterWords(const std::string& text) {
    stringstream ss(text);
    string word;
    string result;

    while (ss >> word) {        //從句子中讀單字存到word變數中(會跳過空白)
        string punctuation;

        // 檢查單詞末尾是否有標點符號
        if (!isalpha(word.back())) {
            punctuation = word.back();
            word = word.substr(0, word.length() - 1);   //用substr刪除字串的最後一個字元
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
    string input_word;      //輸入的句子
    string output_word;     //輸出的句子

    //讀到quit退出
    cout << "Input a string （input 'quit' to exit）: ";
    while (true) {
        getline(cin, input_word);

        if (input_word == "quit") break;

        output_word = replaceFourLetterWords(input_word);
        cout << output_word << endl;

        cout << "Input other string（or input 'quit' exit）:" << endl;
    }

    system("pause");
    return 0;
}