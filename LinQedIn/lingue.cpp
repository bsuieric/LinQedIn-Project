#include "lingue.h"

Lingue::Lingue(string ling, string liv):
    lingua(ling), livello(liv)
{
    if(liv!="Basic" && liv!="Avanzato" && liv!="Eccelente" && liv!="Madre Lingua")
        livello="Non Disponibile";
}

Lingue::~Lingue()
{}

string Lingue::getLingua()const{
    return lingua;
}

void Lingue::setLingua(const string &l){
    lingua=l;
}

string Lingue::getLivello()const{
    return livello;
}

void Lingue::setLivello(const string &liv){
    if(liv!="Basic" && liv!="Avanzato" && liv!="Eccelente" && liv!="Madre Lingua")
        livello="Non Disponibile";
    else
        livello=liv;
}

