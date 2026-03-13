#include <iostream>

int main(){
    
    const char *tajneHaslo = "Programowanie";
    int licznikSamoglosek = 0;

    while(*tajneHaslo != '\0'){
        switch (*tajneHaslo) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                licznikSamoglosek++;
                break;
        }
    *tajneHaslo++;
    }
    std::cout << licznikSamoglosek << std::endl;
    return 0;
}