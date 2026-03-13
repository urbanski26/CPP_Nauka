#include <iostream>
#include <string>

int main(){

    size_t rozmiar;

    std::cout << "Ile znakow ma wiadomosc : ";
    std::cin >> rozmiar;

    char *tajnyKod = new char[rozmiar + 1]{};

    if(tajnyKod != nullptr){
        std::string slowo;
        std::cout << "Podaj hasło : ";
        std::cin >> slowo;

        int klucz;
        std::cout << "Podaj klucz przesuniecia : ";
        std::cin >> klucz;

        size_t i{0};
        while(i < std::size(slowo)){
            tajnyKod[i] = slowo[i] + klucz;
            i++;
        }
    }else{
        std::cout << "Invalid address";
    }

    std::cout << "Kod : " << tajnyKod << std::endl;

    char haslo;
    bool flaga{true};

while(flaga){

    std::cout << "Czy chcesz odszyfrować hasło ? (T/N) : ";
    std::cin >> haslo;
    
    if(haslo == 'T'){
        std::string slowo;
        slowo = tajnyKod;

        std::cout << std::size(slowo);

        int klucz;
        std::cout << "Podaj klucz przesuniecia : ";
        std::cin >> klucz;

        size_t i{0};
        while(i < std::size(slowo)){
            tajnyKod[i] = slowo[i] - klucz;
            i++;
        }

        std::cout << "Hasło to : " << tajnyKod << std::endl;
        flaga = false;

    }else if(haslo == 'N'){
        delete tajnyKod;
        tajnyKod = nullptr;
        flaga = false;
    }else{
        std::cout << "Błąd" << std::endl;
    }
}

    delete tajnyKod;
    tajnyKod = nullptr;

    return 0;
}