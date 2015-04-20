#ifndef LINQEDINADMIN_H
#define LINQEDINADMIN_H
#include"db.h"

class LinQedInAdmin
{
public:
    LinQedInAdmin(DB*);
    ~LinQedInAdmin();

    bool addU(Utente*);
    void removeU(const string&);
    Utente* find(const string&);
    DB* getDB()const;

private:
    DB* db;
};

#endif // LINQEDINADMIN_H
