#include "qevenintvalidator.h"
#include <iostream>
QEvenIntValidator::QEvenIntValidator(QObject *parent) :
    QIntValidator(parent) {
}

QValidator::State QEvenIntValidator::validate(QString &text, int pos) {
    QValidator::State state = QIntValidator::validate(text, pos);
    if(state != QValidator::Invalid) {
        int num = text.toInt();
        state = (num % 2 == 0 ? QValidator::Acceptable : QValidator::Intermediate);
    }
    return state;
}
