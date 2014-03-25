#ifndef QEVENINTVALIDATOR_H
#define QEVENINTVALIDATOR_H

#include <QIntValidator>

class QEvenIntValidator : public QIntValidator
{
    Q_OBJECT
public:
    explicit QEvenIntValidator(QObject *parent = 0);
    QValidator::State validate(QString& text, int pos);
signals:

public slots:

};

#endif // QEVENINTVALIDATOR_H
