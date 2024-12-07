/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <serialcombobox.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *Receive_set_area;
    QWidget *layoutWidget_9;
    QHBoxLayout *horizontalLayout_12;
    QLabel *Checkbits_label_3;
    SerialComboBox *Receive_text_encoder;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_11;
    QLabel *Receive_mode;
    SerialComboBox *Receive_mode_list;
    QGroupBox *Transmit_set_area;
    QWidget *layoutWidget_11;
    QHBoxLayout *horizontalLayout_14;
    QLabel *Checkbits_label_5;
    SerialComboBox *Transmit_text_encoder;
    QWidget *layoutWidget_10;
    QHBoxLayout *horizontalLayout_13;
    QLabel *Transmit_mode;
    SerialComboBox *Transmit_mode_list;
    QGroupBox *Serial_transmit_area;
    QPlainTextEdit *Transmit_data;
    QPushButton *clear_transmit_data;
    QPushButton *Transmit_button;
    QGroupBox *Serial_set_area;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *Stopbits_label;
    SerialComboBox *Stopbits_list;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *COM_label;
    SerialComboBox *Serial_COM_list;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *Databits_lablel;
    SerialComboBox *Databits_list;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Serial_State2;
    QPushButton *open_close_serial;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *Checkbits_label;
    SerialComboBox *Checkbits_list;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Baudrate_label;
    SerialComboBox *Baudrate_list;
    QGroupBox *Serial_receive_area;
    QPlainTextEdit *Receive_data;
    QPushButton *clear_receive_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(982, 763);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMouseTracking(false);
        MainWindow->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Receive_set_area = new QGroupBox(centralwidget);
        Receive_set_area->setObjectName("Receive_set_area");
        Receive_set_area->setGeometry(QRect(490, 300, 231, 111));
        sizePolicy.setHeightForWidth(Receive_set_area->sizePolicy().hasHeightForWidth());
        Receive_set_area->setSizePolicy(sizePolicy);
        layoutWidget_9 = new QWidget(Receive_set_area);
        layoutWidget_9->setObjectName("layoutWidget_9");
        layoutWidget_9->setGeometry(QRect(10, 60, 211, 31));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_9);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        Checkbits_label_3 = new QLabel(layoutWidget_9);
        Checkbits_label_3->setObjectName("Checkbits_label_3");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(10);
        Checkbits_label_3->setFont(font);
        Checkbits_label_3->setMouseTracking(true);
        Checkbits_label_3->setTextFormat(Qt::TextFormat::AutoText);

        horizontalLayout_12->addWidget(Checkbits_label_3);

        Receive_text_encoder = new SerialComboBox(layoutWidget_9);
        Receive_text_encoder->addItem(QString());
        Receive_text_encoder->addItem(QString());
        Receive_text_encoder->setObjectName("Receive_text_encoder");
        Receive_text_encoder->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Receive_text_encoder->sizePolicy().hasHeightForWidth());
        Receive_text_encoder->setSizePolicy(sizePolicy1);

        horizontalLayout_12->addWidget(Receive_text_encoder);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(1, 2);
        layoutWidget_8 = new QWidget(Receive_set_area);
        layoutWidget_8->setObjectName("layoutWidget_8");
        layoutWidget_8->setGeometry(QRect(10, 20, 211, 31));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        Receive_mode = new QLabel(layoutWidget_8);
        Receive_mode->setObjectName("Receive_mode");
        Receive_mode->setFont(font);
        Receive_mode->setMouseTracking(true);
        Receive_mode->setTextFormat(Qt::TextFormat::AutoText);

        horizontalLayout_11->addWidget(Receive_mode);

        Receive_mode_list = new SerialComboBox(layoutWidget_8);
        Receive_mode_list->addItem(QString());
        Receive_mode_list->addItem(QString());
        Receive_mode_list->setObjectName("Receive_mode_list");
        Receive_mode_list->setEnabled(true);
        sizePolicy1.setHeightForWidth(Receive_mode_list->sizePolicy().hasHeightForWidth());
        Receive_mode_list->setSizePolicy(sizePolicy1);
        Receive_mode_list->setFont(font);

        horizontalLayout_11->addWidget(Receive_mode_list);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 2);
        Transmit_set_area = new QGroupBox(centralwidget);
        Transmit_set_area->setObjectName("Transmit_set_area");
        Transmit_set_area->setGeometry(QRect(490, 420, 231, 101));
        sizePolicy.setHeightForWidth(Transmit_set_area->sizePolicy().hasHeightForWidth());
        Transmit_set_area->setSizePolicy(sizePolicy);
        layoutWidget_11 = new QWidget(Transmit_set_area);
        layoutWidget_11->setObjectName("layoutWidget_11");
        layoutWidget_11->setGeometry(QRect(10, 60, 211, 31));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget_11);
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        Checkbits_label_5 = new QLabel(layoutWidget_11);
        Checkbits_label_5->setObjectName("Checkbits_label_5");
        Checkbits_label_5->setFont(font);
        Checkbits_label_5->setMouseTracking(true);
        Checkbits_label_5->setTextFormat(Qt::TextFormat::AutoText);

        horizontalLayout_14->addWidget(Checkbits_label_5);

        Transmit_text_encoder = new SerialComboBox(layoutWidget_11);
        Transmit_text_encoder->addItem(QString());
        Transmit_text_encoder->addItem(QString());
        Transmit_text_encoder->setObjectName("Transmit_text_encoder");
        Transmit_text_encoder->setEnabled(true);
        sizePolicy1.setHeightForWidth(Transmit_text_encoder->sizePolicy().hasHeightForWidth());
        Transmit_text_encoder->setSizePolicy(sizePolicy1);

        horizontalLayout_14->addWidget(Transmit_text_encoder);

        horizontalLayout_14->setStretch(0, 1);
        horizontalLayout_14->setStretch(1, 2);
        layoutWidget_10 = new QWidget(Transmit_set_area);
        layoutWidget_10->setObjectName("layoutWidget_10");
        layoutWidget_10->setGeometry(QRect(10, 20, 211, 31));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget_10);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        Transmit_mode = new QLabel(layoutWidget_10);
        Transmit_mode->setObjectName("Transmit_mode");
        Transmit_mode->setFont(font);
        Transmit_mode->setMouseTracking(true);
        Transmit_mode->setTextFormat(Qt::TextFormat::AutoText);

        horizontalLayout_13->addWidget(Transmit_mode);

        Transmit_mode_list = new SerialComboBox(layoutWidget_10);
        Transmit_mode_list->addItem(QString());
        Transmit_mode_list->addItem(QString());
        Transmit_mode_list->setObjectName("Transmit_mode_list");
        Transmit_mode_list->setEnabled(true);
        sizePolicy1.setHeightForWidth(Transmit_mode_list->sizePolicy().hasHeightForWidth());
        Transmit_mode_list->setSizePolicy(sizePolicy1);
        Transmit_mode_list->setFont(font);

        horizontalLayout_13->addWidget(Transmit_mode_list);

        horizontalLayout_13->setStretch(0, 1);
        horizontalLayout_13->setStretch(1, 2);
        Serial_transmit_area = new QGroupBox(centralwidget);
        Serial_transmit_area->setObjectName("Serial_transmit_area");
        Serial_transmit_area->setGeometry(QRect(20, 370, 461, 151));
        Transmit_data = new QPlainTextEdit(Serial_transmit_area);
        Transmit_data->setObjectName("Transmit_data");
        Transmit_data->setGeometry(QRect(10, 20, 441, 81));
        clear_transmit_data = new QPushButton(Serial_transmit_area);
        clear_transmit_data->setObjectName("clear_transmit_data");
        clear_transmit_data->setGeometry(QRect(360, 110, 91, 31));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(clear_transmit_data->sizePolicy().hasHeightForWidth());
        clear_transmit_data->setSizePolicy(sizePolicy2);
        clear_transmit_data->setFont(font);
        Transmit_button = new QPushButton(Serial_transmit_area);
        Transmit_button->setObjectName("Transmit_button");
        Transmit_button->setGeometry(QRect(260, 110, 91, 31));
        sizePolicy2.setHeightForWidth(Transmit_button->sizePolicy().hasHeightForWidth());
        Transmit_button->setSizePolicy(sizePolicy2);
        Transmit_button->setFont(font);
        Serial_set_area = new QGroupBox(centralwidget);
        Serial_set_area->setObjectName("Serial_set_area");
        Serial_set_area->setGeometry(QRect(490, 20, 231, 271));
        sizePolicy.setHeightForWidth(Serial_set_area->sizePolicy().hasHeightForWidth());
        Serial_set_area->setSizePolicy(sizePolicy);
        Serial_set_area->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        layoutWidget_6 = new QWidget(Serial_set_area);
        layoutWidget_6->setObjectName("layoutWidget_6");
        layoutWidget_6->setGeometry(QRect(10, 140, 211, 31));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        Stopbits_label = new QLabel(layoutWidget_6);
        Stopbits_label->setObjectName("Stopbits_label");
        Stopbits_label->setFont(font);
        Stopbits_label->setMouseTracking(true);
        Stopbits_label->setTextFormat(Qt::TextFormat::AutoText);

        horizontalLayout_7->addWidget(Stopbits_label);

        Stopbits_list = new SerialComboBox(layoutWidget_6);
        Stopbits_list->addItem(QString());
        Stopbits_list->addItem(QString());
        Stopbits_list->setObjectName("Stopbits_list");
        Stopbits_list->setEnabled(true);
        sizePolicy1.setHeightForWidth(Stopbits_list->sizePolicy().hasHeightForWidth());
        Stopbits_list->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(Stopbits_list);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 2);
        layoutWidget = new QWidget(Serial_set_area);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 20, 211, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        COM_label = new QLabel(layoutWidget);
        COM_label->setObjectName("COM_label");
        COM_label->setFont(font);
        COM_label->setMouseTracking(true);
        COM_label->setTextFormat(Qt::TextFormat::AutoText);

        horizontalLayout->addWidget(COM_label);

        Serial_COM_list = new SerialComboBox(layoutWidget);
        Serial_COM_list->setObjectName("Serial_COM_list");
        Serial_COM_list->setEnabled(true);
        sizePolicy1.setHeightForWidth(Serial_COM_list->sizePolicy().hasHeightForWidth());
        Serial_COM_list->setSizePolicy(sizePolicy1);
        Serial_COM_list->setFont(font);

        horizontalLayout->addWidget(Serial_COM_list);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        layoutWidget_5 = new QWidget(Serial_set_area);
        layoutWidget_5->setObjectName("layoutWidget_5");
        layoutWidget_5->setGeometry(QRect(10, 100, 211, 31));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        Databits_lablel = new QLabel(layoutWidget_5);
        Databits_lablel->setObjectName("Databits_lablel");
        Databits_lablel->setFont(font);
        Databits_lablel->setMouseTracking(true);
        Databits_lablel->setTextFormat(Qt::TextFormat::AutoText);

        horizontalLayout_6->addWidget(Databits_lablel);

        Databits_list = new SerialComboBox(layoutWidget_5);
        Databits_list->addItem(QString());
        Databits_list->addItem(QString());
        Databits_list->addItem(QString());
        Databits_list->addItem(QString());
        Databits_list->setObjectName("Databits_list");
        Databits_list->setEnabled(true);
        sizePolicy1.setHeightForWidth(Databits_list->sizePolicy().hasHeightForWidth());
        Databits_list->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(Databits_list);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 2);
        layoutWidget1 = new QWidget(Serial_set_area);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 220, 211, 34));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Serial_State2 = new QLabel(layoutWidget1);
        Serial_State2->setObjectName("Serial_State2");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Serial_State2->sizePolicy().hasHeightForWidth());
        Serial_State2->setSizePolicy(sizePolicy3);
        Serial_State2->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(Serial_State2);

        open_close_serial = new QPushButton(layoutWidget1);
        open_close_serial->setObjectName("open_close_serial");
        open_close_serial->setFont(font);
        open_close_serial->setAutoFillBackground(true);

        horizontalLayout_2->addWidget(open_close_serial);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);
        layoutWidget_7 = new QWidget(Serial_set_area);
        layoutWidget_7->setObjectName("layoutWidget_7");
        layoutWidget_7->setGeometry(QRect(10, 180, 211, 31));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        Checkbits_label = new QLabel(layoutWidget_7);
        Checkbits_label->setObjectName("Checkbits_label");
        Checkbits_label->setFont(font);
        Checkbits_label->setMouseTracking(true);
        Checkbits_label->setTextFormat(Qt::TextFormat::AutoText);

        horizontalLayout_8->addWidget(Checkbits_label);

        Checkbits_list = new SerialComboBox(layoutWidget_7);
        Checkbits_list->addItem(QString());
        Checkbits_list->addItem(QString());
        Checkbits_list->addItem(QString());
        Checkbits_list->setObjectName("Checkbits_list");
        Checkbits_list->setEnabled(true);
        sizePolicy1.setHeightForWidth(Checkbits_list->sizePolicy().hasHeightForWidth());
        Checkbits_list->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(Checkbits_list);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 2);
        layoutWidget_4 = new QWidget(Serial_set_area);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(10, 60, 211, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        Baudrate_label = new QLabel(layoutWidget_4);
        Baudrate_label->setObjectName("Baudrate_label");
        Baudrate_label->setFont(font);
        Baudrate_label->setMouseTracking(true);
        Baudrate_label->setTextFormat(Qt::TextFormat::AutoText);

        horizontalLayout_5->addWidget(Baudrate_label);

        Baudrate_list = new SerialComboBox(layoutWidget_4);
        Baudrate_list->addItem(QString());
        Baudrate_list->addItem(QString());
        Baudrate_list->addItem(QString());
        Baudrate_list->addItem(QString());
        Baudrate_list->addItem(QString());
        Baudrate_list->addItem(QString());
        Baudrate_list->setObjectName("Baudrate_list");
        Baudrate_list->setEnabled(true);
        sizePolicy1.setHeightForWidth(Baudrate_list->sizePolicy().hasHeightForWidth());
        Baudrate_list->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(Baudrate_list);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 2);
        Serial_receive_area = new QGroupBox(centralwidget);
        Serial_receive_area->setObjectName("Serial_receive_area");
        Serial_receive_area->setGeometry(QRect(20, 20, 461, 341));
        sizePolicy.setHeightForWidth(Serial_receive_area->sizePolicy().hasHeightForWidth());
        Serial_receive_area->setSizePolicy(sizePolicy);
        Receive_data = new QPlainTextEdit(Serial_receive_area);
        Receive_data->setObjectName("Receive_data");
        Receive_data->setGeometry(QRect(10, 20, 441, 271));
        sizePolicy.setHeightForWidth(Receive_data->sizePolicy().hasHeightForWidth());
        Receive_data->setSizePolicy(sizePolicy);
        clear_receive_button = new QPushButton(Serial_receive_area);
        clear_receive_button->setObjectName("clear_receive_button");
        clear_receive_button->setGeometry(QRect(360, 300, 91, 31));
        sizePolicy2.setHeightForWidth(clear_receive_button->sizePolicy().hasHeightForWidth());
        clear_receive_button->setSizePolicy(sizePolicy2);
        clear_receive_button->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        Serial_receive_area->raise();
        Serial_set_area->raise();
        Transmit_set_area->raise();
        Receive_set_area->raise();
        Serial_transmit_area->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 982, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Receive_set_area->setTitle(QCoreApplication::translate("MainWindow", "Receive Set", nullptr));
        Checkbits_label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\346\226\207\346\234\254\347\274\226\347\240\201</p></body></html>", nullptr));
        Receive_text_encoder->setItemText(0, QCoreApplication::translate("MainWindow", "UTF-8", nullptr));
        Receive_text_encoder->setItemText(1, QCoreApplication::translate("MainWindow", "GBK", nullptr));

        Receive_mode->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\346\216\245\346\224\266\346\250\241\345\274\217</p></body></html>", nullptr));
        Receive_mode_list->setItemText(0, QCoreApplication::translate("MainWindow", "HEX\346\250\241\345\274\217", nullptr));
        Receive_mode_list->setItemText(1, QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254\346\250\241\345\274\217", nullptr));

        Transmit_set_area->setTitle(QCoreApplication::translate("MainWindow", "Transmit Set", nullptr));
        Checkbits_label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\346\226\207\346\234\254\347\274\226\347\240\201</p></body></html>", nullptr));
        Transmit_text_encoder->setItemText(0, QCoreApplication::translate("MainWindow", "UTF-8", nullptr));
        Transmit_text_encoder->setItemText(1, QCoreApplication::translate("MainWindow", "GBK", nullptr));

        Transmit_mode->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\345\217\221\351\200\201\346\250\241\345\274\217</p></body></html>", nullptr));
        Transmit_mode_list->setItemText(0, QCoreApplication::translate("MainWindow", "HEX\346\250\241\345\274\217", nullptr));
        Transmit_mode_list->setItemText(1, QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254\346\250\241\345\274\217", nullptr));

        Serial_transmit_area->setTitle(QCoreApplication::translate("MainWindow", "Serial Transmit", nullptr));
        clear_transmit_data->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\345\217\221\351\200\201\345\214\272", nullptr));
        Transmit_button->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        Serial_set_area->setTitle(QCoreApplication::translate("MainWindow", "Serial Set", nullptr));
        Stopbits_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\345\201\234\346\255\242\344\275\215</p></body></html>", nullptr));
        Stopbits_list->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        Stopbits_list->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));

        COM_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\347\253\257\345\217\243\345\217\267</p></body></html>", nullptr));
        Databits_lablel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\346\225\260\346\215\256\344\275\215</p></body></html>", nullptr));
        Databits_list->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        Databits_list->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        Databits_list->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        Databits_list->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        Serial_State2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">State</p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        open_close_serial->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        open_close_serial->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        Checkbits_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\346\240\241\351\252\214\344\275\215</p></body></html>", nullptr));
        Checkbits_list->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        Checkbits_list->setItemText(1, QCoreApplication::translate("MainWindow", "Even", nullptr));
        Checkbits_list->setItemText(2, QCoreApplication::translate("MainWindow", "Odd", nullptr));

        Baudrate_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\346\263\242\347\211\271\347\216\207</p></body></html>", nullptr));
        Baudrate_list->setItemText(0, QCoreApplication::translate("MainWindow", "4800", nullptr));
        Baudrate_list->setItemText(1, QCoreApplication::translate("MainWindow", "9600", nullptr));
        Baudrate_list->setItemText(2, QCoreApplication::translate("MainWindow", "19200", nullptr));
        Baudrate_list->setItemText(3, QCoreApplication::translate("MainWindow", "38400", nullptr));
        Baudrate_list->setItemText(4, QCoreApplication::translate("MainWindow", "57600", nullptr));
        Baudrate_list->setItemText(5, QCoreApplication::translate("MainWindow", "115200", nullptr));

        Baudrate_list->setCurrentText(QCoreApplication::translate("MainWindow", "4800", nullptr));
        Serial_receive_area->setTitle(QCoreApplication::translate("MainWindow", "Serial Receive", nullptr));
        clear_receive_button->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
