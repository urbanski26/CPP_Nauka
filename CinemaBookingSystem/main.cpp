#include <iostream>

int main(){
    
    size_t rozmiar;
    std::cout << "Podaj wielkosc rzedu : ";
    std::cin >> rozmiar;

    bool *tablica = new bool [rozmiar]{};

    while(true){
        char opcja;

        std::cout << "----MENU----" << std::endl;
        std::cout << "Opcja 1: Zobacz stan rzędu." << std::endl;
        std::cout << "Opcja 2: Zarezerwuj miejsce." << std::endl;
        std::cout << "Opcja 3: Wyjdź." << std::endl; 

        std::cout << "Opcja : ";
        std::cin >> opcja;

        if(opcja == '1'){
            for(size_t i{0}; i < rozmiar; ++i){
                if(!tablica[i]){
                    std::cout << " [ ] ";
                }else{
                    std::cout << " [X] ";
                }
            }
            std::cout << std::endl;
        }else if(opcja == '2'){
            size_t miejsce;
            std::cout << "Wybierz numer miejsca : ";
            std::cin >> miejsce;

            if(miejsce - 1 >= rozmiar){
                std::cout << "Nie ma takiego miejsca" << std::endl;
            }else if(tablica[miejsce - 1]){
                std::cout << "Miejsce jest już zajęte" << std::endl;
            }else{
                tablica[miejsce - 1] = true;
                std::cout << "Sukces! Miejsce zostało zajęte" << std::endl;
            }
        }else if(opcja == '3'){
            break;
        }
        std::cout << std::endl;
    }

    std::cout << "Koniec programu" << std::endl;

    delete tablica;
    tablica = nullptr;

    return 0;
}