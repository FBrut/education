#include <iostream>
#include <string>


bool get_address_part(std::string str, int n);
int digit(std::string str);
bool check_zero(std::string str);
bool check_IP(std::string str);
bool check_dot_IP(std::string str);
bool check_number(std::string str);

int digit(std::string str)
{
    int counter = 1;
    int nmbr = 0;
    for (int i = str.length() - 1; i >= 0; i--) {
        nmbr += (str[i] - '0') * counter;
        counter *= 10;
    }
    return nmbr;
}

bool check_dot_IP(std::string str)
{
    if (str[0] == '.' || str[str.length() - 1] == '.') return false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.' && str[i + 1] == '.') return false;
        if (str[i] > '9') return false;
    }
    return true;
}

bool check_zero(std::string str)
{
    if (str.size() > 1)
    {
        if (str[0] == '0' && str[0 + 1] >= '0') return false;
    }

    return true;
}

/*
bool check_number(int n)
{
    int number = n;
    std::cout << "number = " << number << std::endl;
    if (number > 255) return false;

}
*/

bool get_address_part(std::string str)
{
    std::string num;
    int number;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '.') {
            num += str[i];
        }
        else
        if (str[i] == '.') {
            if (check_zero(num)) {
                number = digit(num);
            } else return false;
            //check_number(number);
            if (number > 255 ) {
                return false;
            }
            num = "";
        }
        if (i + 1 == str.length()) {
            if (check_zero(num)) {
            }
            else return false;
            number = digit(num);
            //check_number(number);
            if (number > 255) {
                return false;
            }
            num = "";
        }
    }
    return true;
}


bool check_IP(std::string str)
{
    if (!check_dot_IP(str)) return false;
    if (!get_address_part(str)) return false;
    return true;
}

int main() {

    std::string adrIP;

    std::cout << "enter the IP address: " << std::endl;
    std::getline(std::cin, adrIP);

    std::cout << (check_IP(adrIP) ? "Valid" : "Invalid") << std::endl;

    return 0;
}
