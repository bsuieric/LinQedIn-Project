#ifndef LINGUE_H
#define LINGUE_H
#include<string>
using std::string;

class Lingue
{
public:
    Lingue(string, string);
    ~Lingue();

    string getLingua()const;
    void setLingua(const string&);

    string getLivello()const;
    void setLivello(const string&);
private:
    string lingua;
    string livello;
};

#endif // LINGUE_H
