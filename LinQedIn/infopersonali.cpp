#include "infopersonali.h"

InfoPersonali::InfoPersonali(string n,string c,QDate q,string d):
    nome(n),cognome(c),annoNascita(q),descrizione(d)
{}

InfoPersonali::~InfoPersonali()
{}

string InfoPersonali::getNome()const{
    return nome;
}

void InfoPersonali::setNome(const string &n){
    nome=n;
}

string InfoPersonali::getCognome()const{
    return cognome;
}

void InfoPersonali::setCognome(const string &c){
    cognome=c;
}

QDate InfoPersonali::getAnnoNascita()const{
    return annoNascita;
}

void InfoPersonali::setAnnoNascita(const QDate &q){
    annoNascita=q;
}

string InfoPersonali::getDescrizione()const{
    return descrizione;
}

void InfoPersonali::setDescrizione(const string &d){
    descrizione=d;
}

