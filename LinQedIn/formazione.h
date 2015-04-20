#ifndef FORMAZIONE_H
#define FORMAZIONE_H
#include<string>
using std::string;


class Formazione
{
public:
    Formazione(string, int);
    ~Formazione();

    string getPercorso()const;
    void setPercorso(const string&);

    int getAnnoDiploma()const;
    void setAnnoDiploma(int);

private:
    string percorso;
    int annoDiploma;
};

#endif // FORMAZIONE_H
