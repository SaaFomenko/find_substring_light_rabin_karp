#include <iostream>


int simple_string_hash(const std::string& str)
{
    const char* char_str = str.c_str();
    unsigned int hash = 0;
    unsigned int i = 0;

    while (char_str[i] != 0)
    {
        hash += static_cast<int>(char_str[i]);
        ++i;
    }

    return hash;
}

unsigned int find_substring_light_rabin_karp(
    const std::string& str,
    const std::string substr
)
{
    const char* chars = str.c_str();
    const char* subchars = substr.c_str();
    const unsigned int str_size = str.length();
    const unsigned int substr_size = str.length();
    char temp_subchar[substr.length()]{};
    unsigned int search_hash = 0;
    unsigned int current_hash = 0;
    int index = -1;
    int index_end = -1;
    bool isFind = false;
    bool isIndex = false;

    for (int i = 0; i < str.length(); ++i)
    {
        if (substr[0] == str[i])
        {
            index = i;
            index_end = i + substr.length();
        }

        if (index >= i && i <= index_end)
        {
            search_hash += static_cast<int>(subchars[i]);
            current_hash += static_cast<int>(chars[i]);
            temp_subchar[i] = chars[i];
        }

        if (search_hash == current_hash)
        {
            isFind = true;
            for (int i = 0; i < substr_size; ++i)
            {
                if (temp_subchar[i] != chars[i]) isFind = false;
            }

            if (isFind) return index;
        }




    }

    
  
    for (int i = 0; i < str_size; ++i)
    {
        if (i < substr_size)
        {

        }
        

    }
}