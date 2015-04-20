#include "utente.h"

Utente::Utente(string u, string n, string c, QDate d, string descr, Profilo* pr,vector<Rete*> r):
    username(u), info(new InfoPersonali(n,c,d,descr)), p(pr), contact(r)
{}

Utente::~Utente()
{
    if(info)
        delete info;
    if(p)
        delete p;
    for(vector<Rete*>::iterator it=contact.begin();it!=contact.end();++it)
        delete *it;
}

string Utente::getUsername()const{
    return username;
}

void Utente::setUsername(const string& u){
    username=u;
}

InfoPersonali* Utente::getInfo()const{
    return info;
}

Profilo* Utente::getProfilo()const{
    return p;
}

bool Utente::contactIsEmpty()const{
    return contact.empty();
}

int Utente::contactSize()const{
    return contact.size();
}

Rete* Utente::getContact(int i)const{
    vector<Rete*>::const_iterator it=contact.begin()+i;
    return *it;
}

void Utente::addContact(const Rete &co){
    Rete* aux=const_cast<Rete*>(&co);
    contact.push_back(aux);
}

void Utente::removeContact(const string& c){
    for(unsigned int i=0; i<contact.size();++i){
        if(getContact(i)->getContatto()==c){
            delete getContact(i);
            contact.erase(contact.begin()+i);
        }
    }
}

vector<Rete*> Utente::getVectorRete()const{
    return contact;
}





