#include <iostream>

int symbolCommercialAt(std::string str);
bool doubleChar(std::string str);
std::string leftString(std::string str);
std::string rightString(std::string str);
bool checkChar(char ch);
bool checkSpecChars(char ch);
bool emailText_left(std::string str);
bool emailText_right(std::string str);
bool correctEmail (std::string str);


int symbolCommercialAt(std::string str)
{
    int position_AT = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '@') {
            position_AT = i;
        }
    }
    return position_AT;
}

bool doubleChar(std::string str)
{
    for (int i = 1; i < str.length(); ++i) {
        if((str[i] == '@') || (str[i] == '.' && str[i + 1] == '.')) {
            return false;
        }
    }
    return true;
}

std::string leftString(std::string str)
{
    int symbol = symbolCommercialAt(str);
    std::string left;
    for (int i = 0; i < str.length(); i++) {
        if (i < symbol) {
            left += str[i];
        }
    }
    return  left;
}

std::string rightString(std::string str)
{
    int symbol = symbolCommercialAt(str);
    std::string right;
    for (int i = 0; i < str.length(); i++) {
        if (i > symbol) {
            right += str[i];
        }
    }
    return  right;
}

bool checkChar(char ch)
{
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')|| (ch >= '0' && ch <= '9')
    || ch == '.' || ch == '-') {
        return true;
    }
    return false;
}

bool checkSpecChars(char ch)
{
    std::string legalUnit = "!#$%&'*+-/=?^_`{|}~";
    for(unsigned  int i = 0; i < legalUnit.length(); i++){
        if(legalUnit[i] == ch) return true;
    }
    return false;
}

bool emailText_left(std::string str)
{
    std::string left = leftString(str);

    if (left.length() < 1 || left.length() > 64) {
        return false;
    } else if (!doubleChar(left)) {
        return false;
    } else for (int i = 0; i < left.length(); i++) {
        char ch = left[i];
        if(!(checkSpecChars(ch) || checkChar(ch))) {
            return false;
        }
    }
    return true;
}

bool emailText_right(std::string str)
{
    std::string right = rightString(str);

    if (right.length() < 1 || right.length() > 63) {
       return false;
    } else if (!doubleChar(right)) {
        return false;
    } else for (int i = 0; i < right.length(); i++) {
        char ch = right[i];
        if(!(checkChar(ch))) {
            return false;
        }
    }
    return true;
}

bool correctEmail (std::string str)
{
    if ((emailText_left(str)) && (emailText_right(str))) {
        return true;
    }
    return false;
}


int main() {


    std::string email;

    std::cout << "enter address: " << std::endl;
    std::getline (std::cin, email);

    std::cout << (correctEmail (email) ? "Yes" : "No") << std::endl;
}