#include <iostream>

int main(){
    
    int** plansza = new int*[3];
    int cyfra{1};

    for(size_t i{0}; i < 3; ++i){
        plansza[i] = new int[3];
    }
    for(size_t i{0}; i < 3; ++i){
        for(size_t n{0}; n < 3; ++n){
            plansza[i][n] = cyfra;
            cyfra++;
        }
    }
    for(size_t i{0}; i < 3; ++i){
        for(size_t n{0}; n < 3; ++n){
            std::cout << plansza[i][n];
        }
        delete[] plansza[i];
        plansza[i] = nullptr;
        std::cout << std::endl;
    }

    delete[] plansza;
    plansza = nullptr;

    return 0;
}