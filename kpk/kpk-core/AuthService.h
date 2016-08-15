#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include <QObject>

class AuthService : public QObject
{
    Q_OBJECT
public:
    explicit AuthService(QObject *parent = 0);

signals:

public slots:
};

#endif // AUTHSERVICE_H