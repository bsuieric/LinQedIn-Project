#include "profilo.h"

Profilo::Profilo(vector<Competenze*> co,
                 vector<Esperienze*> es,
                 vector<Formazione*> fo,
                 vector<Lingue*> li): c(co), e(es), f(fo), l(li)
{}

Profilo::~Profilo()
{
    //distruzione profonda degli oggetti puntati dal vector
    for(vector<Competenze*>::iterator it=c.begin();it!=c.end();++it)
        delete *it;
    for(vector<Esperienze*>::iterator it=e.begin();it!=e.end();++it)
        delete *it;
    for(vector<Formazione*>::iterator it=f.begin();it!=f.end();++it)
        delete *it;
    for(vector<Lingue*>::iterator it=l.begin();it!=l.end();++it)
        delete *it;
}

bool Profilo::cIsEmpty()const{
    return c.empty();
}

bool Profilo::eIsEmpty()const{
    return e.empty();
}

bool Profilo::fIsEmpty()const{
    return f.empty();
}

bool Profilo::lIsEmpty()const{
    return l.empty();
}


int Profilo::getSizeC()const{
    return c.size();
}

int Profilo::getSizeE()const{
    return e.size();
}

int Profilo::getSizeF()const{
    return f.size();
}

int Profilo::getSizeL()const{
    return l.size();
}


void Profilo::addInC(const Competenze &co){
    Competenze* aux=const_cast<Competenze*>(&co);
    c.push_back(aux);
}

void Profilo::addInE(const Esperienze &es){
    Esperienze* aux=const_cast<Esperienze*>(&es);
    e.push_back(aux);
}

void Profilo::addInF(const Formazione &fo){
    Formazione* aux=const_cast<Formazione*>(&fo);
    f.push_back(aux);
}

void Profilo::addInL(const Lingue &li){
    Lingue* aux=const_cast<Lingue*>(&li);
    l.push_back(aux);
}


void Profilo::removeInC(int i){
    vector<Competenze*>::iterator it=c.begin()+i;
    if(*it)
        delete *it;
    c.erase(it);
}

void Profilo::removeInE(int i){
    vector<Esperienze*>::iterator it=e.begin()+i;
    if(*it)
        delete *it;
    e.erase(it);
}

void Profilo::removeInF(int i){
    vector<Formazione*>::iterator it=f.begin()+i;
    if(*it)
        delete *it;
    f.erase(it);
}

void Profilo::removeInL(int i){
    vector<Lingue*>::iterator it=l.begin()+i;
    if(*it)
        delete *it;
    l.erase(it);
}


Competenze* Profilo::getFromC(int i){
    vector<Competenze*>::iterator it=c.begin()+i;
    return *it;
}

Esperienze* Profilo::getFromE(int i){
    vector<Esperienze*>::iterator it=e.begin()+i;
    return *it;
}

Formazione* Profilo::getFromF(int i){
    vector<Formazione*>::iterator it=f.begin()+i;
    return *it;
}

Lingue* Profilo::getFromL(int i){
    vector<Lingue*>::iterator it=l.begin()+i;
    return *it;
}

