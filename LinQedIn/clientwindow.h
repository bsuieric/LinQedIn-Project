#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H
#include"QDialog"
#include"QLabel"
#include"QGroupBox"
#include"mainwindow.h"
#include"QTextEdit"
#include"QToolBox"
#include"QTableWidget"
#include"linqedinclient.h"
#include"QHeaderView"
#include"QStandardItemModel"
#include"QStandardItem"
#include"QStringList"
#include"QComboBox"

class ClientWindow : public QDialog
{
    Q_OBJECT
public:
    explicit ClientWindow(LinQedInClient*,QWidget *parent = 0);
    ~ClientWindow();

    void setView();

    void loadInfoUtente();
    void loadProfiloUtente();
    void loadContattiUtente();
    void loadFormazioneUtente();
    void loadEsperienzeUtente();
    void loadCompetenzeUtente();
    void loadLingueUtente();

    QTreeWidgetItem* addRoot(const QString&);
    void addChild(QTreeWidgetItem*, const QString&);
    void loadInfoContatto(Utente*);

    void saveModificheInfoPersonali()const;
    void saveModificheCompetenze()const;
    void saveModificheFormazione()const;
    void saveModificheEsperienze()const;
    void saveModificheLingue()const;

private slots:
    void on_listWidgetContatti_doubleClicked(QListWidgetItem *);
    void on_pushButtonEliminaContatto_clicked();
    void on_pushButtonAggiungiFormazione_clicked();
    void on_pushButtonEliminaFormazione_clicked();
    void on_pushButtonAggiungiEsperienze_clicked();
    void on_pushButtonEliminaEsperienze_clicked();
    void on_pushButtonAggiungiCompetenze_clicked();
    void on_pushButtonEliminaCompetenze_clicked();
    void on_pushButtonAggiungiLingue_clicked();
    void on_pushButtonEliminaLingue_clicked();
    void on_pushButtonRicercaContatti_clicked();
    void on_pushButtonAggiungiContatto_clicked();
    void on_pushButtonEsciSalva_clicked();

private:
    QGroupBox *groupBoxInfo;
    QLabel *labelUsername;
    QLabel *labelNome;
    QLabel *labelCognome;
    QLabel *labelNascita;
    QLabel *labelDescrizione;
    QLabel *labelUser;
    QLineEdit *lineEditNome;
    QLineEdit *lineEditCognome;
    QDateEdit *dateEditNascita;
    QTextEdit *textEditDescrizione;
    QPushButton *pushButtonSalva;
    QToolBox *toolBoxProfilo;
    QWidget *pageContatti;
    QListWidget *listWidgetContatti;
    QPushButton *pushButtonEliminaContatto;
    QTreeWidget *treeWidgetInfoContatto;
    QWidget *pageFormazione;
    QPushButton *pushButtonAggiungiFormazione;
    QPushButton *pushButtonEliminaFormazione;
    QTableWidget *tableWidgetFormazione;
    QWidget *pageEsperienze;
    QPushButton *pushButtonAggiungiEsperienza;
    QTableWidget *tableWidgetEsperienze;
    QPushButton *pushButtonEliminaEsperienza;
    QWidget *pageCompetenze;
    QPushButton *pushButtonAggiungiCompetenza;
    QTableWidget *tableWidgetCompetenze;
    QPushButton *pushButtonEliminaCompetenza;
    QWidget *pageLingue;
    QTableWidget *tableWidgetLingue;
    QPushButton *pushButtonAggiungiLingua;
    QPushButton *pushButtonEliminaLingua;
    QGroupBox *groupBoxSearch;
    QListWidget *listWidgetRicerca;
    QLabel *labelRicercaUsername;
    QLabel *labelRicercaUser;
    QLineEdit *lineEditRicercaUsername;
    QPushButton *pushButtonRicerca;
    QPushButton *pushButtonAggiungiContatto;

    LinQedInClient* cl;
};

#endif // CLIENTWINDOW_H
