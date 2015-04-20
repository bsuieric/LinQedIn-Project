#include "formazione.h"

Formazione::Formazione(string p, int a):
    percorso(p),annoDiploma(a)
{}

Formazione::~Formazione()
{}

string Formazione::getPercorso()const{
    return percorso;
}

void Formazione::setPercorso(const string &p){
    percorso=p;
}

int Formazione::getAnnoDiploma()const{
    return annoDiploma;
}

void Formazione::setAnnoDiploma(int a){
    annoDiploma=a;
}
