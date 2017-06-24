#ifndef CHAT_H
#define CHAT_H

#include <QObject>
#include <QString>
#include <QList>
#include <netinet/in.h>
#include <sys/socket.h>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include "chatdef.h"
#include <pthread.h>
#include <arpa/inet.h>
#include <map>
#include <errno.h>

typedef struct
{
    QString name;
    QString ip;
}User;


class Chat : public QObject
{
    Q_OBJECT
public:
    explicit Chat(QObject *parent = 0);

    User self;
//    QList<User*> others;
    //ip is key
    QMap<QString, User*>others;
    int udp_fd;

    pthread_t tid;

    static void* recv_thread(void* ptr);  //为什么加static
    void run();


    void init();

    void handleMsg(const QJsonObject& obj, QString ip);

    void addUser(QString ip, QString name);

    QString getSysName();
    QString getSysIp();

    void send(const QJsonObject& obj, QString ip);

signals:
    void sigNewUser(QString name, QString ip);

public slots:
};

#endif // CHAT_H
