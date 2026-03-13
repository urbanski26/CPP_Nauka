#include <iostream>

int main(){
    
    int wiek;
    double waga;
    double wzrost;
    char plec;

    std::cout << "Podaj wiek : ";
    std::cin >> wiek;

    std::cout << "Podaj wage : ";
    std::cin >> waga;

    std::cout << "Podaj wzrost : ";
    std::cin >> wzrost;

    std::cout << "Podaj płeć ('M'/'K') : ";
    std::cin >> plec;

    bool pelnoletnosc = (wiek > 18);

    double zapotrzebowanie;

    std::cout << std::showpos;

    switch (plec)
    {
    case 'M':
        zapotrzebowanie = ((10 * waga) + (6.25 * wzrost) - (5 * wiek) + 5) * 1.3;
        std::cout << "Zapotrzebowanie kaloryczne dla mężczyzny o podanych danych wynosi : " << static_cast<int>(zapotrzebowanie) << std::endl;
        break;
    case 'K':
        zapotrzebowanie = ((10 * waga) + (6.25 * wzrost) - (5 * wiek) - 161) * 1.3;
        std::cout << "Zapotrzebowanie kaloryczne dla kobiety o podanych danych wynosi : " << static_cast<int>(zapotrzebowanie) << std::endl;
        break; 
    default:
        std::cout << "Nieprawidłowy znak" << std::endl;
    }

    return 0;
}