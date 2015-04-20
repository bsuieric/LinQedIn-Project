#include "competenze.h"

Competenze::Competenze(string c, int v):
    competenza(c),voto(v)
{
    if(v<0 || v>10)
        voto=0;
}

Competenze::~Competenze()
{}

string Competenze::getCompetenza()const{
    return competenza;
}

void Competenze::setCompetenza(const string &c){
    competenza=c;
}

int Competenze::getVoto()const{
    return voto;
}

void Competenze::setVoto(int v){
    if(v<0 || v>10)
        voto=0;
    else
        voto=v;
}
