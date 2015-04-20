#ifndef UTENTEBUSINESS_H
#define UTENTEBUSINESS_H
#include"utente.h"
#include"db.h"

class DB;
class UtenteBusiness : public Utente
{
public:
    UtenteBusiness(string, string, string, QDate, string="", Profilo* = new Profilo(), vector<Rete*> = vector<Rete*>());
    virtual void userSearch(const DB &, const string& u, QList<QString>&);
};

#endif // UTENTEBUSINESS_H
