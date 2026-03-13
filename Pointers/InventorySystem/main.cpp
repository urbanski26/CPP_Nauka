#include <iostream>

int main(){
    
    int *staryMagazyn = new int[3]{10, 20, 30};

    int *nowyMagazyn = new int[5]{};

    for(size_t i{0}; i < 3; ++i){
        nowyMagazyn[i] = staryMagazyn[i];
    }
    nowyMagazyn[3] = 40;
    nowyMagazyn[4] = 50;

    delete[] staryMagazyn;
    staryMagazyn = nullptr;

    staryMagazyn = nowyMagazyn;

    std::cout << "nowy : " << nowyMagazyn << std::endl;
    std::cout << "stary : " << staryMagazyn << std::endl;

    delete[] nowyMagazyn;
    nowyMagazyn = nullptr;
    staryMagazyn = nullptr;
        
    return 0;
}