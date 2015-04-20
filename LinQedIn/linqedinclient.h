#ifndef LINQEDINCLIENT_H
#define LINQEDINCLIENT_H
#include"utente.h"
#include"db.h"

class LinQedInClient
{
public:
    LinQedInClient(DB*, Utente*);
    ~LinQedInClient();

    Utente* getClient()const;

    DB* getDB()const;

    void addContact(const string&);
    void removeContatto(const string&);
private:
    Utente* client;
    DB* db;
};

#endif // LINQEDINCLIENT_H
