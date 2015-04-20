#ifndef RETE_H
#define RETE_H
#include<string>
using std::string;

class Rete
{
public:
    Rete(const string&);
    ~Rete();

    string getContatto()const;
private:
    string contatto;
};

#endif // RETE_H
