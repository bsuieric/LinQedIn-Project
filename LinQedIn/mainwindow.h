#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include<QVBoxLayout>
#include<QGroupBox>
#include<QPushButton>
#include<QLineEdit>
#include<QMenuBar>
#include<QToolBar>
#include<QStatusBar>
#include<adminwindow.h>
#include<clientwindow.h>
#include<linqedinclient.h>
#include"linqedinadmin.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupView();
    DB* getDB()const;
signals:

private slots:
    void admin_clicked();
    void client_clicked();

private:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *groupLayout;
    QGroupBox *adminBox;
    QVBoxLayout *verticalLayout_4;
    QPushButton *admin;
    QGroupBox *clientBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *boxLayout;
    QLineEdit *lineEdit;
    QPushButton *client;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    DB *db;
};

#endif // MAINWINDOW_H
