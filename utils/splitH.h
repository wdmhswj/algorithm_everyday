#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> split(const std::string& data, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(data);
    while(std::getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}