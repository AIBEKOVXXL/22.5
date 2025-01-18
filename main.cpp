#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::map<std::string, std::string>  phone_to_name;
    std::map<std::string, std::vector<std::string>> name_to_phones;

    std::string command;
    while (std::getline(std::cin, command)){
        size_t first_space = command.find(' ');
        if (first_space == std::string::npos) {
            std::string query = command;
            if ( query.find(' ') != std::string::npos) {
                if (phone_to_name.count(query)) {
                    std::cout << phone_to_name[query] << std::endl;
                } else {
                    std::cout << "Number not found" << std::endl;
                }
            } else {
                if (name_to_phones.count(query)) {
                    for (auto phone : name_to_phones[query]) {
                        std::cout << phone << " ";
                    }
                    std::cout << std::endl;
                } else {
                    std::cout << "Name not found" << std::endl;
                }
            }
        }
        else {
            std::string name = command.substr(0, first_space);
            std::string phone = command.substr(first_space + 1);
            
            phone_to_name[phone] = name;
            name_to_phones[name].push_back(phone);
        }
    }
    return 0;
}