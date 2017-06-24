#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* mL = new QVBoxLayout(this);
    QSplitter* spliter = new QSplitter;
    spliter->addWidget(userList = new QListWidget);
    mL->addWidget(spliter);

    QWidget* container;
    spliter->addWidget(container = new QWidget(this));

    QVBoxLayout* vbox = new QVBoxLayout(container);
    vbox->addWidget(msgShow = new QTextBrowser, 3);
    vbox->addWidget(msgInput = new QTextEdit, 1);
    QHBoxLayout* hbox = new QHBoxLayout;
    vbox->addLayout(hbox);
    hbox->addStretch(1);
    hbox->addWidget(setup = new QPushButton("设置"));
    hbox->addWidget(sendMsg = new QPushButton("发送"));

    vbox->setMargin(0);
    hbox->setMargin(0);

    connect(&chat, SIGNAL(sigNewUser(QString,QString)),
            this, SLOT(onNewUser(QString,QString)));
}

void MainWindow::onNewUser(QString name, QString ip)
{
    int count = this->userList->count();
    for(int i = 0; i < count; ++i)
    {
        QListWidgetItem* item = userList->item(i);
        if(item->text().indexOf(ip) != -1)
        {
            // 找到了删除, 过会重新加
            userList->removeItemWidget(item);
            break;
        }
    }
    //重新加
    this->userList->addItem(name+"@"+ip);
}
