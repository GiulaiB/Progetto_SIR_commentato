#include <cassert> //debug (assert)
#include <cmath>
#include <fstream>
#include <iomanip> //setw: specifica la larghezza del campo di visualizzazione
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include "disease.hpp"

//////////////////////////////////////evolution of the disease//////////////////////////////////////

State disease::Disease::evolve_(State const &begin) {
  auto end = State();
  end.s = begin.s - beta_ * begin.i * begin.s; //equation 3a
  if (end.s < 0) {
    end.s = 0; //termina quando nessuno è più suscettibile
  }
  end.r = begin.r + gamma_ * begin.i; //equation 3b
  if (end.r > tot_) {
    end.r = tot_; //termina quando tutti sono guariti/morti
  }
  end.i = begin.i + beta_ * begin.i * begin.s - gamma_ * begin.i; //equation 3c
  if (end.i > tot_) {
    end.i = tot_ - end.r - end.s;
  }
  // I make sure the data is correct
  assert(!(end.s < 0));
  assert(!(end.i < 0));
  assert(!(end.r < 0));
  return end;
};
/*Il linguaggio C fornisce un file di intestazione cassert(o <assert.h>) e una corrispondente
macro assert() che un programmatore può utilizzare per fare asserzioni.
Se l’asserzione risulta falsa, la macro assert() predispone la stampa di un messaggio diagnostico
che descrive la condizione che sarebbe dovuta essere vera ma che non lo era, e poi fa terminare
il programma.
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////
//Creazione del primo elemento

disease::Disease::Disease(std::string p, int n, double inf, double b, double y) : name_{p} {
  assert(b > 0 && b < 1); //condizioni su beta
  assert(y > 0 && y < 1); //condizioni su gamma
  assert(n > 1); //condizioni su n

  tot_ = n;
  beta_ = b / tot_;
  gamma_ = y * 0.1; //perchè 0.1?
  State state_0{(double)n - inf, inf, 0.}; //crea una struttura con i compartimenti {"s", "i", "r"}
  state_.push_back(state_0); //crea lo stato 0 e lo inserisce come primo elemento nel vettore stati
}

/*
push_back(): https://cplusplus.com/reference/vector/vector/push_back/
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////
//Creazione degli elementi successivi

void disease::Disease::setBeta(double b) { beta_ = b / tot_; }
void disease::Disease::setGamma(double g) { gamma_ = g; }
void disease::Disease::evolve(int n) {
  for (int i = 0; i < n; ++i) {
    state_.push_back(evolve_(state_[i])); //aggiunge lo stato i+1 partendo dallo stato i
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//Struttura del file report.txt

void disease::Disease::print() {
  int i = 0;
  auto tab = std::setw(15);
  std::cout << name_ << '\n';
  std::cout << "Current value of R0: " << (tot_ * beta_) / gamma_ << '\n'; //R0
  std::cout << tab << "Day" << tab << "Susceptible" << tab << "Infectuos" << tab
            << "Recovered" << '\n';
  for (auto const it : state_) {
    std::cout << std::setprecision(10) << tab << i << tab << (int)it.s << tab
              << (int)it.i << tab << (int)it.r << '\n';
    ++i;
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//Salva il testo prodotto da print in "report.txt"

void disease::Disease::f_print() { //Sposto l'output su file
  std::ofstream fp; //performs input/output operations on the file they are associated with
  fp.open("report.txt");
  std::cout.rdbuf(fp.rdbuf()); //	.rdbuf: pointer to the associated streambuf object, which is charge of all input/output operations

  print();
  fp.close();
}
