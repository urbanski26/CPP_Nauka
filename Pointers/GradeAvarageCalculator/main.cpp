#include <iostream>

int main(){
    
    size_t rozmiar;
    std::cout << "Ile ocen chcesz wprowadzić?" << std::endl;
    std::cin >> rozmiar;
    
    double *dynamic_array = new double[rozmiar];
    double suma{0.0};

    if(dynamic_array){
        for(size_t i{}; i < rozmiar; i++){
            std::cout << "Ocena nr " << (i + 1) << " : ";
            std::cin >> dynamic_array[i];
            suma += dynamic_array[i];
        }
    }else{
        std::cout << "Nullptr" << std::endl;
    }

    for(size_t i{}; i < rozmiar; i++){
        std::cout << "Ocena [" << (i + 1)<< "] : " << dynamic_array[i] << std::endl;
    }

    double srednia = suma / rozmiar;

    std::cout << suma << std::endl;
    std::cout << rozmiar << std::endl;

    std::cout << "Średnia ocen : " << srednia << std::endl;

    delete[] dynamic_array;
    dynamic_array = nullptr;

    return 0;
}