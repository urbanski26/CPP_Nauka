#include <iostream>

int main(){
    
    int *gigantyczna_tablica {nullptr};
    gigantyczna_tablica = new(std::nothrow) int[10];

    if(!gigantyczna_tablica){
        std::cout << "Błąd: Brak pamieci RAM! Alokacja przerwana." << std::endl;
    }else{
        std::cout << "Sukces! Zaalokowano pamiec." << std::endl;
    }

    std::cout << *gigantyczna_tablica << std::endl;

    *gigantyczna_tablica = 10;

    std::cout << *gigantyczna_tablica << std::endl;


    return 0;
}