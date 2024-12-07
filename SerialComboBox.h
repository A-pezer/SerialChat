#ifndef SERIALCOMBOBOX_H
#define SERIALCOMBOBOX_H

#include <QComboBox>
#include <QSerialPortInfo>

class SerialComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit SerialComboBox(QWidget *parent = nullptr);

protected:
    void showPopup() override;

signals:
    void aboutToShowPopup();

};

#endif // SERIALCOMBOBOX_H
