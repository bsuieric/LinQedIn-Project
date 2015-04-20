#include "linqedinclient.h"

LinQedInClient::LinQedInClient(DB* d, Utente* u): client(u), db(d)
{}

LinQedInClient::~LinQedInClient()
{
    if(client)
        delete client;
    if(db)
        delete db;
}

Utente* LinQedInClient::getClient()const{
    return client;
}

DB* LinQedInClient::getDB()const{
    return db;
}

void LinQedInClient::addContact(const string& s){
    Rete aux(s);
    client->addContact(aux);
}

void LinQedInClient::removeContatto(const string& s){
    client->removeContact(s);
}
