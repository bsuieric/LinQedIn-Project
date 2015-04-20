#ifndef UTENTEEXECUTIVE_H
#define UTENTEEXECUTIVE_H
#include"utente.h"
#include"db.h"

class DB;
class UtenteExecutive : public Utente
{
public:
    UtenteExecutive(string, string, string, QDate, string="", Profilo* = new Profilo(), vector<Rete*> = vector<Rete*>());
    virtual void userSearch(const DB&, const string& u, QList<QString>&) ;
};

#endif // UTENTEEXECUTIVE_H
