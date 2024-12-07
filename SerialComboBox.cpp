#include "SerialComboBox.h"

SerialComboBox::SerialComboBox(QWidget *parent) : QComboBox(parent) {
    // 初始化时可以执行一些设置
}

void SerialComboBox::showPopup()
{
    emit aboutToShowPopup();  // 自定义信号，通知刷新
    QComboBox::showPopup();   // 调用父类的 showPopup()
}

