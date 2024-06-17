//network_helper.h, Matthew Ferguson, 11/10/2023
//network_helper class implementation

#ifndef NETWORK_HELPER_H
#define NETWORK_HELPER_H

#include <QObject>
#include <QtCore>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class network_helper : public QObject {//boilerplate
    Q_OBJECT
    QNetworkAccessManager *manager;
public:
    network_helper();
    void tryHTTPS(QString, QString);
    QString getResponse() const; //Get response

signals:
    void responseReceived();

public slots:
    void replyFinished(QNetworkReply*);

private:
    QString responseText;//store response
};

#endif // NETWORK_HELPER_H
