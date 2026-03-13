#include <iostream>

int main(){
    
    double temperatury [7] {15.2, 12.4, 15.1, 10.2, 5.6, 6.8, 9.9};
    double max{0};
    double min{temperatury[0]};

    for(auto t : temperatury){
        max = t > max ? t : max;
        min = t < min ? t : min;
    }
    std::cout << "Max : " << max << std::endl;
    std::cout << "Min : " << min << std::endl;

    char miasto [] {"Krakow"};
    std::cout << std::size(miasto) << std::endl;
    for(int i {std::size(miasto) - 1}; i >= 0; --i){
        std::cout << miasto[i - 1];
    }
    return 0;
}