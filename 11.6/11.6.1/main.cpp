#include <iostream>
std::string encrypt_caesar(std::string, std::string, int);
std::string decrypt_caesar(std::string, std::string, int);

std::string encrypt_caesar(std::string text, std::string str, int key)
{
    for (int i = 0; i < str.length(); ++i) {
        bool isUpperChar{str[i] >= 'A' && str[i] <= 'Z'};
        bool isLowerChar{str[i] >= 'a' && str[i] <= 'z'};

        if (isUpperChar) {
            if ((str[i] + key) > 'Z') {
                str[i] += key - 'Z' + 'A' - 1;
            } else if ((str[i] + key) < 'A') {
                str[i] += key + 'Z' - 'A' + 1;
            } else {
                str[i] += key;
            }
            text += str[i];
        } else if (isLowerChar) {
            if ((str[i] + key) > 'z') {
                str[i] += key - 'z' + 'a' - 1;
            } else if ((str[i] + key) < 'a') {
                str[i] += key + 'z' - 'a' + 1;
            } else {
                str[i] += key;
            }
            text += str[i];
        }
        if(str[i] == ' ') {
            str[i] = ' ';
            text += str[i];
        }
    }
    return text;
}

std::string decrypt_caesar(std::string text, std::string str, int key)
{
    return encrypt_caesar(text, str, -key);

}

int main() {
    std::string str;
    std::string text;
    int key;

    std::cout << "Enter the string:\n";
    std::getline(std::cin, str);

    std::cout << "Enter key (number of letter shifts):\n";
    std::cin >> key;

    str = encrypt_caesar(text, str, key);
    std::cout << str << std::endl;

    std::cout << "Decipher: \n";
    str = decrypt_caesar(text, str,  key);
    std::cout << str << std::endl;
}