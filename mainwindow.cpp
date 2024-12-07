#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <Windows.h>
#include <QString>
#include <QByteArray>
#include <QSplitter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , serialPort(new QSerialPort(this)) // 创建串口对象
{
    ui->setupUi(this);
    this->setWindowTitle("SerialChat"); // 设置窗口标题
    this->setWindowIcon(QIcon(":/logo.ico"));
    // 获取uiQGroupBox所有控件
    QGroupBox *sendGroupBox = ui->Serial_transmit_area;
    QGroupBox *receiveGroupBox = ui->Serial_receive_area;
    QGroupBox *SerialSetBox = ui->Serial_set_area;
    QGroupBox *ReceiveSetBox = ui->Receive_set_area;
    QGroupBox *TransmitSetBox = ui->Transmit_set_area;

    // 获取uiQPushButton所有控件
    QPushButton *clear_receive_button = ui->clear_receive_button;
    QPushButton *Transmit_button = ui->Transmit_button;
    QPushButton *clear_transmit_data = ui->clear_transmit_data;

    // 获取uiQPlainTextEdit所有控件
    QPlainTextEdit *Receive_data = ui->Receive_data;
    QPlainTextEdit *Transmit_data = ui->Transmit_data;

    QSplitter *mainSplitter = new QSplitter(Qt::Horizontal, this);    // 创建水平 QSplitter
    QSplitter *leftSplitter = new QSplitter(Qt::Vertical, this);    // 创建左侧的垂直 QSplitter
    QSplitter *rightSplitter = new QSplitter(Qt::Vertical, this);

    //按钮大小固定
    clear_receive_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    clear_receive_button->setFixedSize(80, 30);
    Transmit_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    Transmit_button->setFixedSize(80, 30);
    clear_transmit_data->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    clear_transmit_data->setFixedSize(80, 30);

    // 为 receiveGroupBox 创建一个垂直布局
    QVBoxLayout *layout2 = new QVBoxLayout(receiveGroupBox);
    layout2->addWidget(Receive_data);

    //  receiveGroupBox创建水平布局，将按钮放置到右侧
    QHBoxLayout *receivebuttonlayout = new QHBoxLayout();
    receivebuttonlayout->addStretch();            // 添加弹性空间
    receivebuttonlayout->addWidget(clear_receive_button);   // 按钮放在右侧

    layout2->addLayout(receivebuttonlayout); // 将按钮的水平布局添加到垂直布局中
    receiveGroupBox->setLayout(layout2);   // 应用布局到 receiveGroupBox

    // 为 sendGroupBox 创建一个垂直布局
    QVBoxLayout *layout1 = new QVBoxLayout(sendGroupBox);
    layout1->addWidget(Transmit_data);

    //  sendGroupBox创建水平布局，将按钮放置到右侧
    QHBoxLayout *sendButthonlayout = new QHBoxLayout();
    sendButthonlayout->addStretch();            // 添加弹性空间
    sendButthonlayout->addWidget(Transmit_button);
    sendButthonlayout->addWidget(clear_transmit_data);

    layout1->addLayout(sendButthonlayout); // 将按钮的水平布局添加到垂直布局中
    sendGroupBox->setLayout(layout1);   // 应用布局到 sendGroupBox

    // 左侧
    leftSplitter->addWidget(receiveGroupBox);
    leftSplitter->addWidget(sendGroupBox);
    // 右侧
    rightSplitter->addWidget(SerialSetBox);
    rightSplitter->addWidget(ReceiveSetBox);
    rightSplitter->addWidget(TransmitSetBox);

    mainSplitter->addWidget(leftSplitter);
    mainSplitter->addWidget(rightSplitter);
    // 设置右侧配置区的比例
    rightSplitter->setStretchFactor(0, 1);  // 串口配置区
    rightSplitter->setStretchFactor(1, 1);  // 接收配置区
    rightSplitter->setStretchFactor(2, 1);  // 发送配置区

    // 设置左侧区域的比例
    leftSplitter->setStretchFactor(0, 1);  // 接收区
    leftSplitter->setStretchFactor(1, 1);  // 发送区

    mainSplitter->setStretchFactor(0, 2);  // 左侧区域占较大空间
    rightSplitter->setFixedWidth(240);  // 设置右侧区域的固定宽度
    mainSplitter->setStretchFactor(1, 0);  // 右侧配置区不伸缩

    // 设置 QSplitter 作为主窗口的中央部件
    setCentralWidget(mainSplitter);
    resize(800, 600);

    ui->open_close_serial->setStyleSheet(
        "QPushButton {"
        "    background-color: #f0f0f0; "  // 默认背景色
        "    color: black; "
        "    border-radius: 5px; "  // 圆角效果
        "    border: 1px solid gray; "
        "    padding: 2px white; "
        "}"
        "QPushButton:hover {"
        "    background-color: #e3e3e3; "
        "    color: gray;"
        "    border-radius: 5px;"
        "    border: 1px solid blue; "
        "    padding: 2px;"
        "}"
        );
    ui->Serial_State2->setStyleSheet(
        "   background-color: red; "
        "    border-radius: 5px; "
        );

    // 初始化波特率
    ui->Baudrate_list->setCurrentText("9600");  // 默认值

    // 初始化数据位
    ui->Databits_list->setCurrentText("8");  // 默认值

    // 初始化停止位
    ui->Stopbits_list->setCurrentText("1");  // 默认值

    // 禁用发送按钮
    ui->Transmit_button->setEnabled(false);

    connect(ui->Serial_COM_list, &SerialComboBox::aboutToShowPopup, this, &MainWindow::refreshSerialPorts);    // 连接 QComboBox 的 showPopup() 信号到刷新串口列表的槽函数
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::onSerialDataReceived);  // 连接 readyRead 信号到槽函数
    connect(ui->Transmit_data, &QPlainTextEdit::textChanged, this, &MainWindow::onTransmitDataChanged);     // 绑定发送区内容变化的信号到自定义槽函数

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_close_serial_clicked()
{
    static bool isSerialOpen = false;  // 用 static 保持状态跨函数调用

    if (isSerialOpen)
    {
        // 如果串口已打开，执行关闭串口的操作
        serialPort->close();
        // 解除禁用下拉框
        ui->Serial_COM_list->setEnabled(true);
        ui->Baudrate_list->setEnabled(true);
        ui->Databits_list->setEnabled(true);
        ui->Stopbits_list->setEnabled(true);
        ui->Checkbits_list->setEnabled(true);
        // 禁用发送按钮
        ui->Transmit_button->setEnabled(false);

        ui->open_close_serial->setText("打开串口");              // 修改按钮文本为“打开串口”
        ui->open_close_serial->setStyleSheet(
            "QPushButton#open_close_serial {"
            "    background-color: #f0f0f0; "                   // 默认背景色灰色
            "    color: black; "
            "    border-radius: 5px; "                          // 圆角效果
            "    border: 1px solid gray; "
            "    padding: 2px white; "
            "}"
            "QPushButton#open_close_serial:hover {"             //悬停效果深灰色
            "    background-color: #e3e3e3; "
            "    color: gray;"
            "    border-radius: 5px;"
            "    border: 1px solid blue; "
            "    padding: 2px;"
            "}"
            );
        ui->Serial_State2->setStyleSheet(
            "   background-color: red; "
            "    border-radius: 5px; "
            );
        isSerialOpen = false;
    }
    else
    {
        // 设置串口号
        QString portInfo = ui->Serial_COM_list->currentText();  // 获取当前选中的端口信息
        QString portName = portInfo.split(" - ").first();       // 提取实际端口号部分
        serialPort->setPortName(portName);

        // 设置波特率
        int baudRate = ui->Baudrate_list->currentText().toInt();
        serialPort->setBaudRate(baudRate);

        // 设置数据位
        QSerialPort::DataBits dataBits;
        switch (ui->Databits_list->currentText().toInt())
        {
            case 5: dataBits = QSerialPort::Data5; break;
            case 6: dataBits = QSerialPort::Data6; break;
            case 7: dataBits = QSerialPort::Data7; break;
            case 8: dataBits = QSerialPort::Data8; break;
            default:
                QMessageBox::warning(this, "错误", "无效的数据位");
                return;
        }
        serialPort->setDataBits(dataBits);

        // 设置停止位
        QSerialPort::StopBits stopBits;
        switch (ui->Stopbits_list->currentText().toInt())
        {
            case 1: stopBits = QSerialPort::OneStop; break;
            case 2: stopBits = QSerialPort::TwoStop; break;
            default:
                QMessageBox::warning(this, "错误", "无效的停止位");
                return;
        }
        serialPort->setStopBits(stopBits);

        // 设置校验位
        QSerialPort::Parity parity;
        if (ui->Checkbits_list->currentText() == "None")
        {
            parity = QSerialPort::NoParity;
        }
        else if (ui->Checkbits_list->currentText() == "Even")
        {
            parity = QSerialPort::EvenParity;
        }
        else if (ui->Checkbits_list->currentText() == "Odd")
        {
            parity = QSerialPort::OddParity;
        }
        else
        {
            QMessageBox::warning(this, "错误", "无效的校验位");
            return;
        }
        serialPort->setParity(parity);

        // 尝试打开串口
        if (serialPort->open(QIODevice::ReadWrite))
        {
            // 如果串口未打开，执行打开串口的操作
            ui->open_close_serial->setText("关闭串口");  // 修改按钮文本为“关闭串口”
            ui->open_close_serial->setStyleSheet(
                "QPushButton {"
                "    background-color: #ffcccc; "
                "    color: black; "
                "    border: 1px solid gray; "
                "    border-radius: 5px; "  // 圆角效果
                "    padding: 2px white; "
                "}"
                "QPushButton:hover {"
                "    background-color: pink; "
                "    color: gray; "
                "    border: 1px solid gray; "
                "    border-radius: 5px; "  // 圆角效果
                "    padding: 2px white; "
                "}"
                );
            ui->Serial_State2->setStyleSheet(
                "    background-color: #22c55e;"
                "    border-radius: 5px; "
                );
            // 禁用下拉框
            ui->Serial_COM_list->setEnabled(false);
            ui->Baudrate_list->setEnabled(false);
            ui->Databits_list->setEnabled(false);
            ui->Stopbits_list->setEnabled(false);
            ui->Checkbits_list->setEnabled(false);
            // 解除禁用发送按钮
            ui->Transmit_button->setEnabled(true);
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowTitle("提示");
            msgBox.setText("无法打开串口: " + serialPort->errorString());
            msgBox.setStyleSheet("QMessageBox { font-family: '微软雅黑'; font-size: 12pt; }");
            msgBox.exec();
        }

        isSerialOpen = true;
    }
}

void MainWindow::refreshSerialPorts()
{
    QString currentPort = ui->Serial_COM_list->currentText();    // 保存当前选择的端口
    ui->Serial_COM_list->clear();                        // 清空现有的串口列表

    // 重新添加可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QString portInfo = info.portName() + " - " + info.description();
        ui->Serial_COM_list->addItem(portInfo);
    }

    int index = ui->Serial_COM_list->findText(currentPort);    // 恢复之前选择的端口
    if (index != -1)
    {
        ui->Serial_COM_list->setCurrentIndex(index);
    }
    else
    {
        ui->Serial_COM_list->setCurrentIndex(-1);  // 设置为空
    }
}

QByteArray convertToGBK(const QString& text)
{
    // 将 QString 转为 std::wstring
    std::wstring wstr = text.toStdWString();

    // 获取转换后需要的缓冲区大小
    int size = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);

    // 分配缓冲区并进行转换
    QByteArray byteArray(size, 0);
    WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, byteArray.data(), size, nullptr, nullptr);

    return byteArray;
}

void MainWindow::on_Transmit_button_clicked()
{
    QString dataToSend = ui->Transmit_data->toPlainText();    // 获取输入框中的数据
    QString Transmit_mode = ui->Transmit_mode_list->currentText();    // 获取当前模式
    QString Transmit_encoder = ui->Transmit_text_encoder->currentText();// 获取编码类型

    QByteArray byteArray; // 准备发送的数据
    qint64 bytesWritten = 0;

    if(Transmit_mode == "文本模式")
    {
        if(Transmit_encoder == "UTF-8")
        {
            byteArray = dataToSend.toUtf8(); // 转为 UTF-8 字节数组
        }
        else if(Transmit_encoder == "GBK")
        {
            byteArray = convertToGBK(dataToSend);
        }
    }
    else if(Transmit_mode == "HEX模式")
    {
        // 将格式化后的文本转换为 QByteArray
        QByteArray hexData;
        QStringList hexList = dataToSend.split(' ');  // 以空格分割
        for (const QString &hex : hexList)
        {
            bool ok;
            hexData.append(static_cast<char>(hex.toUInt(&ok, 16)));  // 转为字节
            if (!ok)
            {
                QMessageBox::critical(this, "错误", "输入的 HEX 数据格式不正确！");
                return;
            }
        }

        qint64 bytesWritten = serialPort->write(hexData);
        if (bytesWritten == -1)
        {
            QMessageBox::critical(this, "错误", "发送数据失败: " + serialPort->errorString());
        }
    }
    else
    {
        QMessageBox::critical(this, "错误", "未知发送模式");
        return;
    }
    bytesWritten = serialPort->write(byteArray);

    if (bytesWritten == -1)
    {
        QMessageBox::critical(this, "错误", "发送数据失败: " + serialPort->errorString());
    }
}

void MainWindow::onSerialDataReceived()
{
    QString Receive_mode = ui->Receive_mode_list->currentText();    // 获取当前模式
    QString Receive_encoder = ui->Receive_text_encoder->currentText();// 获取编码类型
    // 从串口读取所有数据
    QByteArray data = serialPort->readAll();
    QString receivedData;

    // 将数据转为字符串并追加到接收区
    if(Receive_mode == "文本模式")
    {
        if(Receive_encoder == "UTF-8")
        {
            receivedData = QString::fromUtf8(data);
        }
        else if(Receive_encoder == "GBK")
        {
            receivedData = QString::fromLocal8Bit(data);
        }
    }
    else if(Receive_mode == "HEX模式")
    {
        receivedData = data.toHex(' ').toUpper();  // 转为大写且用空格分隔
    }

    ui->Receive_data->insertPlainText(receivedData);    // 显示到接收区

    // 滚动到底部以显示最新数据
    QTextCursor cursor = ui->Receive_data->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->Receive_data->setTextCursor(cursor);
}

void MainWindow::on_clear_transmit_data_clicked()
{
    ui->Transmit_data->clear();
}


void MainWindow::on_clear_receive_button_clicked()
{
    ui->Receive_data->clear();
}

void MainWindow::onTransmitDataChanged()
{
    QString text = ui->Transmit_data->toPlainText();    // 获取当前输入框的内容
    QString Transmit_mode = ui->Transmit_mode_list->currentText();      // 获取当前模式

    // 如果当前模式是 "HEX模式"，则进行十六进制字符验证
    if(Transmit_mode == "HEX模式")
    {
        QString formattedText;  // 用来存储合法字符的文本

        // 遍历每个字符并验证是否符合十六进制规则
        for (int i = 0; i < text.length(); ++i)
        {
            QChar c = text.at(i).toUpper();                             // 将字符转为大写，确保 'a' 和 'A' 都是合法的
            if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))       // 验证字符是否在 '0' 到 '9' 或 'A' 到 'F' 范围内
            {
                formattedText.append(c);
                // 如果已经有两个字符，插入一个空格
                if (formattedText.length() % 3 == 2)
                {
                    formattedText.append(' ');
                }
            }
        }

        // 去掉末尾多余的空格
        if (formattedText.endsWith(' '))
        {
            formattedText.chop(1);
        }

        // 禁用信号，防止信号递归触发
        disconnect(ui->Transmit_data, &QPlainTextEdit::textChanged, this, &MainWindow::onTransmitDataChanged);

        // 设置过滤后的文本为新的内容
        ui->Transmit_data->setPlainText(formattedText);

        // 保持光标位置在文本的末尾
        QTextCursor cursor = ui->Transmit_data->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->Transmit_data->setTextCursor(cursor);

        // 重新连接信号，以便继续响应文本变化
        connect(ui->Transmit_data, &QPlainTextEdit::textChanged, this, &MainWindow::onTransmitDataChanged);
    }
}









