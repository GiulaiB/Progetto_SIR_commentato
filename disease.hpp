#ifndef DISEASE_HPP
#define DISEASE_HPP

#include <vector>

#include "structures.hpp"

namespace disease {
    class Disease {
    private: //attributi privati
        std::string name_;
        std::vector<State> state_; //vettori di stati
        double tot_;
        double gamma_;
        double beta_;

    public:
        Disease(std::string p, int n, double inf, double b, double y);

        //////////////////////////////////////////////////////////////////////////////////
        State evolve_(
            State const& begin);  // It evolves the State of the private vector.
        //////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////
        void setBeta(double b);  // Set beta of the class.
        //////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////
        void setGamma(double g);  // Set gamma of the class.
        //////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////
        void evolve(int n);  // It evolves and pushes back day by day the state_ .
        //////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////
        void print();  // It prints the table on the console.
        //////////////////////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////////////////////
        void f_print();  // It prints the table on file.
        ///////////////////////////////////////////////////////////////////////////////////
    };
}  // namespace disease

#endif