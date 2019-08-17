#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QtSerialPort>
#include <QSerialPortInfo>
#include <QMainWindow>
//#include <QtSerialPort/QSerialPort>
//#include <QtSerialPort/QSerialPortInfo>
#include <QJsonDocument>
#include <QJsonObject>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QSerialPort serial;

private:
    void dadosRecebidos();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_fechar_clicked();
    void on_btn_abrir_clicked();
    void on_btn_ativar_clicked();
    void on_btn_desativar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
