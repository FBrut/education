<<<<<<< HEAD
//ïğîâåğêà íàïèñàíèÿ IP àäğåñà
=======
//Ğ¿Ñ€Ğ¾Ğ²ĞµÑ€ĞºĞ° Ğ½Ğ°Ğ¿Ğ¸ÑĞ°Ğ½Ğ¸Ñ IP Ğ°Ğ´Ñ€ĞµÑĞ°
>>>>>>> 611d1d0f115a071b6a0b49598c5dfafbad1ab4a0

#include <iostream>
#include <string>
#include <sstream>

bool digit_IP(std::string str);
bool control_IP(std::string str);
bool digit(std::string str);


bool control_IP(std::string str)
{
    if (str[0] == '.' || str[str.length() - 1] == '.') return false;
	
	for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '.' && str[i + 1] == '.') return false;
    }

    if(!digit(str)) return false;

    return true;
}


bool digit(std::string str)
{
    std::string s;
    int i = 0;
    s = str;

    while (s[i])
    {
        if(s[i]=='.') {
            s[i]=' ';
        }
        i++;
    }


    std::stringstream strm;
    strm << s;
    std::string a, b, c, d;
    strm >> a >> b >> c >> d;

    if(!digit_IP(a)) return false;
	if(!digit_IP(b)) return false;
	if(!digit_IP(c)) return false;
	if(!digit_IP(d)) return false;

    return true;
}

bool digit_IP(std::string str)
{
    if(str.size() > 1)
    {
	    if(str[0] == '0' && str[0 + 1] != '.') return false;
    }

	for (int i = 0; i < str.length(); i++)
    {
    	if(str[i] < '0' || str[i] > '9') return false;
    }

	int n = std::stoi(str);
    if (n < 0 || n > 255) return false;

    return true;
}

int main() {

    std::string adrIP;

    std::cout << "enter the IP address: " << std::endl;
    std::getline(std::cin, adrIP);

    std::cout << (control_IP(adrIP) ? "Yes" : "No") << std::endl;
}