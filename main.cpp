#include <iostream>

int simple_string_hash(const std::string &str)
{
    const char *char_str = str.c_str();
    unsigned int hash = 0;
    unsigned int i = 0;

    while (char_str[i] != 0)
    {
        hash += static_cast<int>(char_str[i]);
        ++i;
    }

    return hash;
}

int find_substring_light_rabin_karp(
    const std::string &str,
    const std::string &substr)
{
    const char *chars = str.c_str();
    const char *subchars = substr.c_str();
    const unsigned int str_size = str.length();
    const unsigned int substr_size = substr.length();
    unsigned int search_hash = simple_string_hash(substr);
    unsigned int current_hash = 0;
    int index = -1;
    int end_index = 0;
    bool isFind = false;

    for (int i = 0; i < str_size; ++i)
    {
        if (i == 0)
        {
            for (int j = 0; j < substr_size; ++j)
            {
                end_index = i + j;
                // if (end_index >= str_size)
                //     return index;
     
                current_hash += static_cast<int>(chars[end_index]);
            }
        }
        else
        {
            end_index = i + substr_size - 1;
            if (end_index >= str_size)
                return index;

            current_hash = current_hash - static_cast<unsigned int>(chars[i - 1]) +
                           static_cast<unsigned int>(chars[end_index]);
        }

        if (current_hash == search_hash)
        {
            isFind = true;
            for (int j = 0; j < substr_size; ++j)
            {
                end_index = i + j;
                if (end_index >= str_size)
                    return index;

                if (chars[end_index] != subchars[j])
                {
                    isFind = false;
                    break;
                }
            }

            if (isFind)
            {
                index = i;
                return index;
            }
        }
    }

    return index;
}

int main()
{
    const std::string str_lable = "Введите строку, в которой будет осуществляться поиск: ";
    const std::string substr_lable = "Введите подстроку, которую нужно найти: ";

    std::string exit_substr = "exit";

    std::string str = "";
    std::string substr = "";

    int find_index = -1;

    std::cout << str_lable;
    std::getline(std::cin, str);

    do
    {
        std::cout << substr_lable;
        std::getline(std::cin, substr);

        find_index = find_substring_light_rabin_karp(str, substr);

        if (find_index != -1)
        {
            std::cout << "Подстрока " << substr << " найдена по индксу " << find_index << '\n';
        }
        else
        {
            std::cout << "Подстрока " << substr << " не найдена. \n";
        }

    } while (substr != exit_substr);

    return 0;
}