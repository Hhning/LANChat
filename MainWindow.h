#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include <QListWidget>

#include <QTextBrowser>

#include <QTextEdit>

#include <QPushButton>

#include <QSplitter>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include "Chat.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

    Chat chat;
    //left
    QListWidget* userList;
    //right
    QTextBrowser* msgShow;
    QTextEdit* msgInput;
    QPushButton* sendMsg;
    QPushButton* setup;


signals:

public slots:
    void onNewUser(QString name, QString ip);
};

#endif // MAINWINDOW_H
