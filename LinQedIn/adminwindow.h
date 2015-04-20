#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H
#include"QDialog"
#include"QGroupBox"
#include"QLabel"
#include"QDateEdit"
#include"QLineEdit"
#include"QPushButton"
#include"QListWidget"
#include"QTreeWidget"
#include"QTreeWidgetItem"
#include"QComboBox"
#include"QHBoxLayout"
#include"linqedinadmin.h"
#include"QHeaderView"

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(LinQedInAdmin*, QWidget *parent = 0);
    ~AdminWindow();

    void setupView();

    void loadInfoUtente(Utente*);

    void loadListaUtenti();

    QTreeWidgetItem* addRoot(const QString&);

    void addChild(QTreeWidgetItem*, const QString&);

    void resetCampiAddUtente();

    void setComboBoxTypeChange(Utente*);
signals:

private slots:

    void on_listViewUtenti_itemDoubleClicked(QListWidgetItem*);
    void on_pushButtonCerca_clicked();
    void on_pushButtonAdd_clicked();
    void on_pushButtonElimina_clicked();
    void on_pushButtonESCI_clicked();
    void on_comboBoxType_change();

private:
    QGroupBox *groupBoxAdd;
    QLabel *labelUAdd;
    QLabel *labelNAdd;
    QLabel *labelCAdd;
    QLabel *labelDAdd;
    QDateEdit *dataEditAdd;
    QLineEdit *lineEditCAdd;
    QLineEdit *lineEditNAdd;
    QLineEdit *lineEditUAdd;
    QPushButton *pushButtonAdd;
    QGroupBox *groupBoxIscritti;
    QLineEdit *lineEditU;
    QPushButton *pushButtonCerca;
    QListWidget *listViewUtenti;
    QPushButton *pushButtonElimina;
    QTreeWidget *treeWidgetUtente;
    QComboBox *comboBox;
    QPushButton *pushButtonESCI;
    QLabel *label_listaUtenti;
    QComboBox *comboBoxTypeChange;
    QLabel *labelTree;
    QLabel *labelTreeUsername;


    LinQedInAdmin* a;
};

#endif // ADMINWINDOW_H
