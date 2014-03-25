#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->intLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(intEditTextChanged(const QString&)));
    connect(ui->doubleLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(doubleEditTextChanged(const QString&)));
    connect(ui->myLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(myEditTextChanged(const QString&)));

    intValidator = new QIntValidator(20, 500, this);
    ui->intLineEdit->setValidator(intValidator);

    doubleValidator = new QDoubleValidator(this);
    ui->doubleLineEdit->setValidator(doubleValidator);

    evenValidator = new QEvenIntValidator(this);
    ui->myLineEdit->setValidator(evenValidator);
}

void MainWindow::intEditTextChanged(const QString& text) {
    QString str = text;
    int position = 0;
    QIntValidator *validator = (QIntValidator*)ui->intLineEdit->validator();
    QValidator::State state = validator->validate(str, position);
    changeColorBy(state, ui->intLineEdit);
}

void MainWindow::doubleEditTextChanged(const QString &text) {
    QString str = text;
    int position = 0;
    QDoubleValidator* validator = (QDoubleValidator*)ui->doubleLineEdit->validator();
    QValidator::State state = ui->doubleLineEdit->validator()->validate(str, position);
    changeColorBy(state, ui->doubleLineEdit);
}

void MainWindow::myEditTextChanged(const QString &text) {
    QString str = text;
    int position = 0;
    QEvenIntValidator* validator = (QEvenIntValidator*)ui->myLineEdit->validator();
    QValidator::State state = validator->validate(str, position);
    changeColorBy(state, ui->myLineEdit);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::changeColorBy(QValidator::State state, QLineEdit *sender) {
    switch(state) {
    case QValidator::Acceptable:
        sender->setStyleSheet("background: white");
        break;
    case QValidator::Intermediate:
        sender->setStyleSheet("background: yellow");
        break;
    case QValidator::Invalid:
        sender->setStyleSheet("background: pink");
        break;
    }
}
