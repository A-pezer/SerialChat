#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QSerialPort"
#include "QSerialPortInfo"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_open_close_serial_clicked();

    void refreshSerialPorts();

    void on_Transmit_button_clicked();

    void on_clear_transmit_data_clicked();

    void on_clear_receive_button_clicked();

    void onSerialDataReceived(); // 用于接收串口数据的槽函数

    void onTransmitDataChanged();

private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;  // 串口对象
};
#endif // MAINWINDOW_H
