#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&serial,
            SIGNAL(readyRead()),
            this,
            SLOT(dadosRecebidos()));

    for(auto& item : QSerialPortInfo::availablePorts())
        ui->box_serial->addItem(item.portName());
    for(auto& item : QSerialPortInfo::standardBaudRates())
        ui->box_velocidade->addItem(QString::number(item));

}

void MainWindow::dadosRecebidos(){
    auto data= serial.readAll();
    qDebug() << "Oi" << endl;

    auto dados = QJsonDocument::fromJson(data).object().toVariantMap();
    if(dados.contains("SENSOR"))
           ui->ldir_value->setText(dados["SENSOR"].toString());


}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_btn_abrir_clicked()
{
    serial.setPortName(ui->box_serial->currentText());
    serial.setBaudRate(ui->box_velocidade->currentText().toInt());

    if(serial.open(QIODevice::ReadWrite)){
        ui->status_conexao->setText("Status: Conectado");
    }
}



void MainWindow::on_btn_fechar_clicked()
{
    serial.close();
    ui->status_conexao->setText("Status: Desconectado");
}

void MainWindow::on_btn_ativar_clicked()
{
    serial.write("{\"ALARME\":1");
    ui->statusAlarme->setText("Ativado");
}

void MainWindow::on_btn_desativar_clicked()
{
    serial.write("{\"ALARME\":0");
    ui->statusAlarme->setText("Desativado");
}
