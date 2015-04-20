#ifndef COMPETENZE_H
#define COMPETENZE_H
#include<string>
using std::string;

class Competenze
{
public:
    Competenze(string , int);
    ~Competenze();

    string getCompetenza()const;
    void setCompetenza(const string&);

    int getVoto()const;
    void setVoto(int);
private:
    string competenza;
    int voto;
};

#endif // COMPETENZE_H
