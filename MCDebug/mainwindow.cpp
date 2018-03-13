#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	m_socket = new QUdpSocket(this);
	m_socket->bind(QHostAddress("127.0.0.1"),12345);
	connect(m_socket,SIGNAL(readyRead()),this,SLOT(socketReadyRead()));
	ui->tableWidget->setColumnCount(4);
	connect(ui->clearPushButton,SIGNAL(clicked(bool)),this,SLOT(clearButtonClicked()));
}

MainWindow::~MainWindow()
{
	delete ui;
}
void MainWindow::socketReadyRead()
{
	char datagrambuffer[4096];
	while (m_socket->hasPendingDatagrams())
	{
		int len = m_socket->readDatagram(datagrambuffer,4096);
		QByteArray buf(datagrambuffer,len);
		QJsonObject obj = QJsonDocument::fromBinaryData(buf).object();
		ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
		ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(obj.value("sender").toString()));
		ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(obj.value("status").toString()));
		//emit incomingJson();
	}
}
void MainWindow::clearButtonClicked()
{
	ui->tableWidget->setRowCount(0);
}
