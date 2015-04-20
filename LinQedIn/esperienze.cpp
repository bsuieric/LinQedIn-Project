#include "esperienze.h"

Esperienze::Esperienze(string e, QDate i, QDate f):
    esperienza(e),inizioEsp(i),fineEsp(f)
{}

Esperienze::~Esperienze()
{}

string Esperienze::getEsperienza()const{
    return esperienza;
}

void Esperienze::setEsperienza(const string &e){
    esperienza=e;
}

QDate Esperienze::getInizioEsp()const{
    return inizioEsp;
}

void Esperienze::setInizioEsp(const QDate & i){
    inizioEsp=i;
}

QDate Esperienze::getFineEsp()const{
    return fineEsp;
}

void Esperienze::setFineEsp(const QDate & f){
    fineEsp=f;
}

