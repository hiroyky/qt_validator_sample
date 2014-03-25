#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QValidator>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QLineEdit>
#include "qevenintvalidator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void intEditTextChanged(const QString& text);
    void doubleEditTextChanged(const QString& text);
    void myEditTextChanged(const QString& text);

private:
    Ui::MainWindow *ui;
    QIntValidator *intValidator;
    QDoubleValidator *doubleValidator;
    QEvenIntValidator* evenValidator;

    void changeColorBy(QValidator::State state, QLineEdit* sender);
};

#endif // MAINWINDOW_H
