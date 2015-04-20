#include "rete.h"

Rete::Rete(const string& c):contatto(c){}

Rete::~Rete(){}

string Rete::getContatto()const{
    return contatto;
}

