/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QLabel *label;
    QLabel *label_2;
    QCheckBox *checkBox;
    QComboBox *comboBox;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(412, 503);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 210, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 210, 75, 23));
        dateEdit = new QDateEdit(centralWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(160, 50, 121, 31));
        dateEdit->setDateTime(QDateTime(QDate(2018, 7, 14), QTime(0, 0, 0)));
        dateEdit->setCalendarPopup(true);
        dateEdit_2 = new QDateEdit(centralWidget);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(160, 90, 121, 31));
        dateEdit_2->setDateTime(QDateTime(QDate(2018, 7, 15), QTime(0, 0, 0)));
        dateEdit_2->setCalendarPopup(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 50, 51, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 90, 51, 31));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(160, 130, 121, 31));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(210, 160, 71, 31));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 210, 75, 23));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 250, 91, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(46, 23, 41, 16));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 270, 361, 171));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 20, 221, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 412, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "GET", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Show Chart", nullptr));
        dateEdit->setDisplayFormat(QApplication::translate("MainWindow", "dd.MM.yyyy", nullptr));
        dateEdit_2->setDisplayFormat(QApplication::translate("MainWindow", "dd.MM.yyyy", nullptr));
        label->setText(QApplication::translate("MainWindow", "Begin Date", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "End Date", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "Show Hours", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "00", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "01", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "02", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "03", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "04", nullptr));
        comboBox->setItemText(5, QApplication::translate("MainWindow", "05", nullptr));
        comboBox->setItemText(6, QApplication::translate("MainWindow", "06", nullptr));
        comboBox->setItemText(7, QApplication::translate("MainWindow", "07", nullptr));
        comboBox->setItemText(8, QApplication::translate("MainWindow", "08", nullptr));
        comboBox->setItemText(9, QApplication::translate("MainWindow", "09", nullptr));
        comboBox->setItemText(10, QApplication::translate("MainWindow", "10", nullptr));
        comboBox->setItemText(11, QApplication::translate("MainWindow", "11", nullptr));
        comboBox->setItemText(12, QApplication::translate("MainWindow", "12", nullptr));
        comboBox->setItemText(13, QApplication::translate("MainWindow", "13", nullptr));
        comboBox->setItemText(14, QApplication::translate("MainWindow", "14", nullptr));
        comboBox->setItemText(15, QApplication::translate("MainWindow", "15", nullptr));
        comboBox->setItemText(16, QApplication::translate("MainWindow", "16", nullptr));
        comboBox->setItemText(17, QApplication::translate("MainWindow", "17", nullptr));
        comboBox->setItemText(18, QApplication::translate("MainWindow", "18", nullptr));
        comboBox->setItemText(19, QApplication::translate("MainWindow", "19", nullptr));
        comboBox->setItemText(20, QApplication::translate("MainWindow", "20", nullptr));
        comboBox->setItemText(21, QApplication::translate("MainWindow", "21", nullptr));
        comboBox->setItemText(22, QApplication::translate("MainWindow", "22", nullptr));
        comboBox->setItemText(23, QApplication::translate("MainWindow", "23", nullptr));
        comboBox->setItemText(24, QApplication::translate("MainWindow", "24", nullptr));

        pushButton_3->setText(QApplication::translate("MainWindow", "Zoom Reset", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Application Output", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Api Key", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "a6297ab5c9c2459c8656f532772b5f49", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
