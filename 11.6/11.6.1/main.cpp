//Шифр цезаря.

#include <iostream>
std::string encrypt_caesar(std::string, int);
std::string decrypt_caesar(std::string, int);

std::string encrypt_caesar(std::string str, int key)
{
    key = (key % 26);
    if (key < 0) {
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                if (str[i + 1] == 'A') {
                    str[i] = 'Z';
                }
                str[i] = str[i] + key;
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                key = (key % 26);
                str[i] = str[i] + key;
            }
            if(str[i] == ' ') {
                str[i] = ' ';
            }
        }
    }
    for (int i = 0; i < str.length(); ++i) {

        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + key;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] + key;
        }
        if(str[i] == ' ') {
            str[i] = ' ';
        }
    }
    return str;
}

std::string decrypt_caesar(std::string str, int key)
{
    return encrypt_caesar(str, -key);
}

int main() {
    std::string str;
    int key;

    std::cout << "Enter the string:\n";
    std::getline(std::cin, str);

    std::cout << "Enter key (number of letter shifts):\n";
    std::cin >> key;

    str = encrypt_caesar(str, key);
    std::cout << str << std::endl;

    std::cout << "Decipher: \n";
    str = decrypt_caesar(str,  key);
    std::cout << str << std::endl;
}
