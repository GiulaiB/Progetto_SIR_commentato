//******************************************
//  SIR model by Belardinelli & Ronchetti
//******************************************

#include "disease.hpp"
constexpr int N_START = 5; //Starting Number of Infected People
constexpr int L = 150; //Length and Heigth of the Grid
constexpr double BETA = 0.1;
constexpr double GAMMA = 0.9;
int main() {
    try {
        std::string name;
        int option;
       
        std::cout << "Welcome to SIR simulator!\n";
        std::cout << "Please insert the name of the disease:";
        std::cin >> name;

        int days = 1000;
        disease::Disease d(name, L * L, N_START, BETA, GAMMA);
        
        d.evolve(days);
        
        std::cout << "Simulation succefully run!\n";
        d.f_print();
    
    }
    catch (std::runtime_error& e) {
        std::cerr << e.what();
    }
}
