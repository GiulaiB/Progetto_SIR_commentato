//*******************************************************************************************
//
//  Simulation of an epidemic disease by the SIR model
//  Belardinelli, Ronchetti
//
//*******************************************************************************************

#include "disease.hpp"
constexpr int NUM_INITIAL_INFECTED = 5;
constexpr int DIM = 150;
constexpr double BETA = 0.5;
constexpr double GAMMA = 0.5;
int main() {
    try {
        std::string name;
        int option;
       
        std::cout << "Welcome to SIR simulator!\n";
        std::cout << "Please insert the name of the disease:";
        std::cin >> name;

        int days = 500;
        disease::Disease d(name, DIM * DIM, NUM_INITIAL_INFECTED, BETA, GAMMA);
        
        d.evolve(days);
        
        std::cout << "Simulation succefully run!\n";
        d.f_print();
    
    }
    catch (std::runtime_error& e) {
        std::cerr << e.what();
    }
}

