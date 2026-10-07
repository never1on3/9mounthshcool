#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <string>

bool OnlyTextInput(const std::string& str)
{
    if (str.empty()) return false;
    for (char const& c : str)
    {
        if (!std::isalpha(static_cast<unsigned char>(c)))
        {
            return false;
        }
    }
    return true;
}
std::string getTextInput()
{
    std::string textInput{};
    while(true) 
    {
        if (std::cin >> textInput)
        {
            if (OnlyTextInput(textInput))
            {
                return textInput;
            }
        }
        std::cout << "Error! Only Text input";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
int getNumberInput()
{
    #define RESET   "\033[0m"
    #define RED     "\033[31m"
    #define GREEN   "\033[1;32m"
    while (true)
    {
        int numberInput{0};
        if (std::cin >> numberInput)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return numberInput;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << RED;
        std::cerr << "Error: Invalid input. Please enter a valid number.\n";
        std::cout << RESET;
    }
}

auto addPizza(std::string a, int b, bool c)
{
    return a, b, c;
}

int main()
{
    std::map<std::string, std::pair<int, bool>> pizza;
    pizza.emplace("melon", std::make_pair(7, true));

    for (auto it = pizza.begin(); it != pizza.end(); ++it) {
        std::cout << it->first << " : "
            << it->second.first << " " << it->second.second << "\n";
    }
}