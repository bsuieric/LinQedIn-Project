#include "linqedinadmin.h"

LinQedInAdmin::LinQedInAdmin(DB* d):db(d)
{}

LinQedInAdmin::~LinQedInAdmin()
{
    if(db)
        delete db;
}

bool LinQedInAdmin::addU(Utente * u){
    return db->addUtenti(u);
}

void LinQedInAdmin::removeU(const string& u){
    db->removeUtente(u);
}

Utente* LinQedInAdmin::find(const string& u){
    return db->findU(u);
}

DB* LinQedInAdmin::getDB()const{
    return db;
}


