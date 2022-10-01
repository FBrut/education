//крестики-нолики, проверка записи игры
//
#include <iostream>

bool check_symbol(std::string str);
char check_row(std::string str);

bool check_symbol(std::string str)
{
    if (str.length() != 9) {
        return false;
    }

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == 'X' || str[i] == 'O' || str[i] == '.') {
            return true;
        } else {
            return false;
        }
    }
}


char check_row(std::string str)
{
    char ch = '.';
    if (str[0] == 'X' && str[1] == 'X' && str[2] == 'X') {
        ch = 'X';
    }
    if (str[0] == 'O' && str[1] == 'O' && str[2] == 'O') {
        ch = 'O';
    }
    return ch;
}

int main() {
    std::string str1, str2, str3;
    std::cout << "enter three table rows: " << std::endl;

    std::cin >> str1;
    std::cin >> str2;
    std::cin >> str3;

    std::string concatenated_string = str1 + str2 + str3;

    if (check_symbol(concatenated_string)) {
        int x = 0, o = 0, dot = 0;
        std::string winn = "";
        char ch;

        for (char i: concatenated_string) {
            if (i == 'X') {
                x++;
            } else if (i == 'O') {
                o++;
            } else if (i == '.') {
                dot++;
            }
        }

        if((x + o) < dot){
            std::cout << "\nNobody\n";
        } else 
                //Строки
                for (int i = 0; i < 7; i += 3) {
                    std::string str = "";
                    for (int j = i; j < i + 3; ++j) {
                        char ch = concatenated_string[j];
                        str += ch;
                    }
                    ch = check_row(str);
                    if (ch == 'X' || ch == 'O'){
                        winn += ch;
                    }
                }
                //Колонки
                for (int i = 0; i < 3; ++i) {
                    std::string str = "";
                    for (int j = i; j < 9; j += 3) {
                        char ch = concatenated_string[j];
                        str += ch;
                    }
                    ch = check_row(str);
                    if (ch == 'X' || ch == 'O'){
                        winn += ch;
                    }
                }
                //Диагонали
                std::string str_L = "";
                for (int i = 0; i < 9; i += 4) {
                    char ch = concatenated_string[i];
                    str_L += ch;
                }
                ch = check_row(str_L);
                if (ch == 'X' || ch == 'O'){
                    winn += ch;
                }

                std::string str_R = "";
                for (int i = 2; i < 7; i += 2) {
                    char ch = concatenated_string[i];
                    str_R += ch;
                }
                ch = check_row(str_R);
                if (ch == 'X' || ch == 'O'){
                    winn += ch;
                }

                if ((winn != "X" || winn != "O") && dot == 0 ) {
                    std::cout << "Nobody";
                } else if (winn == "X" && o == x - 1) {
                    std::cout << "Petya won";
                } else if (winn == "O" && x == o) {
                    std::cout << "Vanya won";
                }  else {
                    std::cout << "Incorrect!!!";
                }
            } 
            else {std::cout << "Incorrect!!!";
        }
        return 0;
}

