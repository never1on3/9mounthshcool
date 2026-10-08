#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <string>
#include <utility>

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
    while (true)
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
        int numberInput{ 0 };
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

void AddPizza(std::map<std::string, std::pair<int, bool>>& pizzaResult,
    const std::string& name, int price, bool value)
{
    pizzaResult[name] = { price, value };
}

int main()
{
    std::map<std::string, std::pair<int, bool>> pizza;
    pizza.emplace("melon", std::make_pair(7, true));

    std::cout << "Add New Pizza?: ";
    {
        std::string yesOrNo{ "no" };
        yesOrNo = { getTextInput() };
        std::transform(yesOrNo.begin(), yesOrNo.end(), yesOrNo.begin(), [](const char c)
            {
                return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
            });
        if (yesOrNo == "yes" || yesOrNo == "y")
        {
            std::cout << "\=========  ok  =========\n1.Name | 2. Price | 3. IS availble?\n";
            std::string name{ getTextInput() };
            int price{ getNumberInput() };
            bool valeuAvailble{ false };
            while (true)
            {
                std::cout << "Enter 1 - ready\nEnter 2 - not ready\nValue = ";
                int value{ getNumberInput() };
                if (value == 1)
                {
                    std::cout << "\nAlright\n";
                    bool valeuAvailble = { true };
                    break;
                }
                if (value == 2)
                {
                    std::cout << "\nAlright\n";
                    break;
                }
            }
            AddPizza(pizza, name, price, valeuAvailble);
        }
        else
        {
            std::cout << "Oh, common bro... bruh\n";
        }
    }

    for (const auto& [name, info] : pizza)
    {
        int price = info.first;
        bool value = info.second;
        std::cout << '\n' << name << ' ' << price
            << ' ' << value << std::endl;
    }
}