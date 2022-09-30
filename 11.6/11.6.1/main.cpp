//Шифр цезаря.

#include <iostream>
#include <iostream>

std::string encrypt_caesar(std::string, int);
std::string decrypt_caesar(std::string, int);

std::string encrypt_caesar(std::string str, int key)
{
    if(abs(key) > 26) {
        key = (key % 26);
    }

    if (key < 0) {
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                if ((str[i] + key) < 'A') {
                    str[i] = 'Z' + (key + (str[i] - 'A' + 1));
                } else str[i] = str[i] + key;
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                if ((str[i] + key) < 'a') {
                    str[i] = 'z' + (key + (str[i] - 'a' + 1));
                } else str[i] = str[i] + key;
            }
        }    
    }        
    if (key > 0) {
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                if ((str[i] + key) > 'Z') {
                    str[i] = 'A' + (key - ('Z' - str[i] + 1));
                } else str[i] = str[i] + key;
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                if ((str[i] + key) > 'z') {
                    str[i] = 'a' + (key - ('z' - str[i] + 1));
                } else str[i] = str[i] + key;
            }
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
