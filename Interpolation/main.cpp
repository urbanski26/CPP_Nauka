#include <iostream>
#include <cmath>

int main(){

    int n = 5;
    double xi[5]  = {10.0, 50.0, 90.0, 20.0, 80.0};
    double yi[5]  = {10.0, 80.0, 20.0, 60.0, 90.0};
    double Hi[5]  = {200.0, 500.0, 300.0, 400.0, 600.0};
    double Ti[5]  = {15.0, 10.0, 13.0, 12.0, 8.0};
    double RHi[5] = {60.0, 80.0, 65.0, 75.0, 85.0};

    double x = 10.0;
    double y = 10.0;
    double H = 200.0;

    double licznik_T{0.0}, mianownik_T{0.0};
    double licznik_RH{0.0}, mianownik_RH{0.0};

    double *gotowe_T{nullptr}, *gotowe_RH{nullptr};

    double T;
    double RH;

    for(size_t i{0}; i < n; ++i){

        if(!gotowe_T){
            double diff_H = H - Hi[i];
            if(diff_H == 0){
                gotowe_T = &Ti[i];
            }else{
                double wi_T = pow(diff_H, -4);
                mianownik_T += wi_T;
                licznik_T += Ti[i] * wi_T;
            }
        }
        if(!gotowe_RH){
            double diff_x = x - xi[i];
            double diff_y = y - yi[i];

            double distance = pow(diff_x, 2) + pow(diff_y, 2) + pow((H - Hi[i]), 2);

            if(distance == 0){
                gotowe_RH = &RHi[i];
            }else{
                double wi_RH = pow(distance, -2);
                mianownik_RH += wi_RH;
                licznik_RH += RHi[i] * wi_RH;
            }
        }
    }
    if(gotowe_T != nullptr){
        T = *gotowe_T;
    }else{
        T = licznik_T / mianownik_T;
    }
    if(gotowe_RH != nullptr){
        RH = *gotowe_RH;
    }else{
        RH = licznik_RH / mianownik_RH;
    }

    std::cout << "Wynik dla punktu x =" << x << " y =" << y << " H =" << H << ":" << std::endl;
    std::cout << "Temperatura: " << T << " stopni Celsjusza" << std::endl;
    std::cout << "Wilgotnosc:  " << RH << " %" << std::endl;

    return 0;
}