// Валидация IP-адреса
//
// Пользователь вводит строку, задающую IP-адрес через стандартный ввод.
// В результате программа должна вывести слово Valid, если адрес корректен,
// и слово Invalid, если это не так.

#include <iostream>
#include <string>

bool check_IP(std::string);
std::string get_address_part(std::string, int);
int digit(std::string);
bool check_zero(std::string str);
bool check_symbol_IP(std::string str);

bool check_symbol_IP(std::string str)
{
    if (str[0] == '.' || str[str.length() - 1] == '.') return false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.' && str[i + 1] == '.') return false;
        if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.') return false;
    }
    return true;
}

int digit(std::string str)
{
    int counter = 1;
    int nmbr = 0;
    for (int i = str.length() - 1; i >= 0; --i) {
        nmbr += (str[i] - '0') * counter;
        counter *= 10;
    }
    return nmbr;
}

bool check_zero(std::string str)
{
    if (str.size() >= 2)
    {
        if (str[0] == '0' && str[0 + 1] >= '0') return false;
    }

    return true;
}

std::string get_address_part(std::string str, int okt)
{
    std::string str_d;
    int counter = okt;
    int n = 0;

    for (int j = 0; j < str.length(); ++j) {
        if (!(str[j] == '.' || str[j] == str.length())) {
            str_d += str[j];
        } else if (str[j] == '.') {
            n += 1;
            if (counter == n) {
                n = 0;
                return str_d;
            }
            str_d = "";
        }
    }
}

bool check_IP(std::string str)
{
    if (!check_symbol_IP(str)) return false;
    std::string str_dig;
    for (int i = 0; i < 4; ++i) {
        int okt = i + 1;
        str_dig = get_address_part(str, okt);

        if (check_zero(str_dig)) {
            int n = digit(str_dig);
            if (n < 0 || n > 255) return false;
        } else return false;
    }

    return true;
}

int main() {

    std::string adrIP;

    std::cout << "enter the IP address: " << std::endl;
    std::getline(std::cin, adrIP);

    std::cout << (check_IP(adrIP) ? "Valid" : "Invalid") << std::endl;

    return 0;
}
