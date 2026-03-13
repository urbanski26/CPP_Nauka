#include <iostream>

int main(){
    
    std::string db_numerKonta = "PL99 1020 3040 5060";
    double db_saldo = 5000.00;

    const std::string& widokKonta = db_numerKonta;
    const double& widokSalda = db_saldo;

    double& procesorTransakcji = db_saldo;

    std::cout << "Stan poczatkowy bazy: " << db_saldo << " PLN\n";

    procesorTransakcji += 3200.50;
    procesorTransakcji -= 150.00;

    std::cout << "Konto " << widokKonta << " po transakcjach: " << widokSalda << " PLN\n";

    return 0;
}