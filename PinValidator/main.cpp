#include <iostream>

int main(){
    
    const int proby{3};
    size_t i{0};
    int pin{123};
    int u_pin;

    do
    {
        std::cout << "Podaj pin : ";
        std::cin >> u_pin;
        if(u_pin == pin){
            std::cout << "Zamek otwarty" << std::endl;
            return 0;
        }else{
            std::cout << "Nieprawidłowy pin, spróbuj ponownie." << std::endl;
        }
        ++i;
    }while (i < proby);

    std::cout << "Alarm! Zablokowano system" << std::endl;
    return 0;
}