#include <iostream>
#include <vector>
#include <cmath> 

struct BazaStacji {
    std::vector<double> xi;
    std::vector<double> yi;
    std::vector<double> Hi;
    std::vector<double> Ti;
    std::vector<double> RHi;
};

struct Wyniki {
    double T;
    double RH;
};

Wyniki interpolacja(double x, double y, double H, const BazaStacji& stacje) {
    
    double licznik_T = 0.0, mianownik_T = 0.0;
    double licznik_RH = 0.0, mianownik_RH = 0.0;

    const double* gotowe_T = nullptr;
    const double* gotowe_RH = nullptr;

    for (size_t i = 0; i < stacje.Hi.size(); ++i) {
        
        double Hi = stacje.Hi[i]; 

        if (!gotowe_T) { 
            double diff_H = H - Hi;
            
            if (diff_H == 0.0) {
                gotowe_T = &stacje.Ti[i]; 
            } else {
                double wi_T = std::pow(diff_H, -4);
                mianownik_T += wi_T;
                licznik_T += stacje.Ti[i] * wi_T;
            }
        }

        if (!gotowe_RH) {
            double diff_x = x - stacje.xi[i];
            double diff_y = y - stacje.yi[i];
            
            double dystans_3d = (diff_x * diff_x) + (diff_y * diff_y) + ((H - Hi) * (H - Hi));

            if (dystans_3d == 0.0) {
                gotowe_RH = &stacje.RHi[i]; 
            } else {
                double wi_RH = std::pow(dystans_3d, -2);
                mianownik_RH += wi_RH;
                licznik_RH += stacje.RHi[i] * wi_RH;
            }
        }
    }

    double T = gotowe_T ? *gotowe_T : (licznik_T / mianownik_T);
    double RH = gotowe_RH ? *gotowe_RH : (licznik_RH / mianownik_RH);

    return {T, RH}; 
}

int main() {
    BazaStacji stacje = {
        {10, 50, 90, 20, 80},
        {10, 80, 20, 60, 90},
        {200, 500, 300, 400, 600},
        {15.0, 10.0, 13.0, 12.0, 8.0},
        {60, 80, 65, 75, 85}
    };

    Wyniki wynik = interpolacja(100.0, 200.0, 150.0, stacje);

    std::cout << "Temperatura: " << wynik.T << " C\n";
    std::cout << "Wilgotnosc: " << wynik.RH << " %\n";

    return 0;
}