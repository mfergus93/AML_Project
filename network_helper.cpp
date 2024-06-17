//network_helper.cpp, Matthew Ferguson, 11/10/2023
//network_helper implementation

#include "network_helper.h"
#include <QEventLoop>
#include <QDebug>
#include <QSslConfiguration>

network_helper::network_helper() {
    manager = new QNetworkAccessManager();

    // Connects finished signal to replyFinished slot
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

void network_helper::tryHTTPS(QString hostName, QString inputText) {//HTTPS Post
    QNetworkRequest request;//create a request
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();//SSL config obj
    config.setProtocol(QSsl::TlsV1_2);//Protocol
    request.setSslConfiguration(config);//set SSL
    request.setUrl(QUrl(hostName));//URL
    request.setRawHeader(QByteArray("Content-Type"), QByteArray("text/plain"));//Header

    QByteArray postData = inputText.toUtf8();
    manager->post(request, postData);//Post
//    qDebug() << request.url();
}

void network_helper::replyFinished(QNetworkReply* reply) {//Get Response
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();

        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);//Parse Json reply
        if (!jsonDoc.isNull() && jsonDoc.isObject())
        {
            QJsonObject jsonObj = jsonDoc.object();
            if (jsonObj.contains("result") && jsonObj["result"].isString())
            {
                responseText = jsonObj["result"].toString();
                emit responseReceived(); //Emit response signal
            }
        }
    }
}
QString network_helper::getResponse() const {//Get response
    return responseText;
}
