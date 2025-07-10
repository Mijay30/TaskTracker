/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *Titlu;
    QLineEdit *Descriere;
    QLineEdit *Data;
    QLineEdit *Finalizat;
    QPushButton *pushButtonAdd;
    QDateEdit *dateEditDueDate;
    QLineEdit *lineEditTitle;
    QLineEdit *lineEditDescription;
    QCheckBox *checkBoxCompleted;
    QTableWidget *tableWidgetTasks;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonExport;
    QPushButton *pushButtonImport;
    QComboBox *comboBoxStyle;
    QPushButton *buttonStergeTot;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuTasks;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Titlu = new QLineEdit(centralwidget);
        Titlu->setObjectName("Titlu");
        Titlu->setGeometry(QRect(70, 20, 41, 21));
        Descriere = new QLineEdit(centralwidget);
        Descriere->setObjectName("Descriere");
        Descriere->setGeometry(QRect(40, 50, 71, 21));
        Data = new QLineEdit(centralwidget);
        Data->setObjectName("Data");
        Data->setGeometry(QRect(70, 80, 41, 21));
        Finalizat = new QLineEdit(centralwidget);
        Finalizat->setObjectName("Finalizat");
        Finalizat->setGeometry(QRect(50, 110, 61, 21));
        pushButtonAdd = new QPushButton(centralwidget);
        pushButtonAdd->setObjectName("pushButtonAdd");
        pushButtonAdd->setGeometry(QRect(260, 80, 100, 32));
        dateEditDueDate = new QDateEdit(centralwidget);
        dateEditDueDate->setObjectName("dateEditDueDate");
        dateEditDueDate->setGeometry(QRect(130, 80, 110, 22));
        lineEditTitle = new QLineEdit(centralwidget);
        lineEditTitle->setObjectName("lineEditTitle");
        lineEditTitle->setGeometry(QRect(130, 20, 281, 21));
        lineEditDescription = new QLineEdit(centralwidget);
        lineEditDescription->setObjectName("lineEditDescription");
        lineEditDescription->setGeometry(QRect(130, 50, 281, 21));
        checkBoxCompleted = new QCheckBox(centralwidget);
        checkBoxCompleted->setObjectName("checkBoxCompleted");
        checkBoxCompleted->setGeometry(QRect(130, 110, 21, 20));
        tableWidgetTasks = new QTableWidget(centralwidget);
        if (tableWidgetTasks->columnCount() < 4)
            tableWidgetTasks->setColumnCount(4);
        tableWidgetTasks->setObjectName("tableWidgetTasks");
        tableWidgetTasks->setGeometry(QRect(0, 140, 411, 301));
        tableWidgetTasks->setColumnCount(4);
        tableWidgetTasks->horizontalHeader()->setVisible(true);
        tableWidgetTasks->horizontalHeader()->setCascadingSectionResizes(false);
        pushButtonDelete = new QPushButton(centralwidget);
        pushButtonDelete->setObjectName("pushButtonDelete");
        pushButtonDelete->setGeometry(QRect(260, 110, 100, 32));
        pushButtonExport = new QPushButton(centralwidget);
        pushButtonExport->setObjectName("pushButtonExport");
        pushButtonExport->setGeometry(QRect(370, 80, 100, 32));
        pushButtonImport = new QPushButton(centralwidget);
        pushButtonImport->setObjectName("pushButtonImport");
        pushButtonImport->setGeometry(QRect(370, 110, 100, 32));
        comboBoxStyle = new QComboBox(centralwidget);
        comboBoxStyle->addItem(QString());
        comboBoxStyle->addItem(QString());
        comboBoxStyle->addItem(QString());
        comboBoxStyle->addItem(QString());
        comboBoxStyle->setObjectName("comboBoxStyle");
        comboBoxStyle->setGeometry(QRect(150, 110, 103, 32));
        buttonStergeTot = new QPushButton(centralwidget);
        buttonStergeTot->setObjectName("buttonStergeTot");
        buttonStergeTot->setGeometry(QRect(420, 140, 100, 32));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 37));
        menuTasks = new QMenu(menubar);
        menuTasks->setObjectName("menuTasks");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuTasks->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Titlu->setText(QCoreApplication::translate("MainWindow", "Titlu:", nullptr));
        Descriere->setText(QCoreApplication::translate("MainWindow", "Descriere", nullptr));
        Data->setText(QCoreApplication::translate("MainWindow", "Data:", nullptr));
        Finalizat->setText(QCoreApplication::translate("MainWindow", "Finalizat", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("MainWindow", "Adaug\304\203", nullptr));
        checkBoxCompleted->setText(QString());
        pushButtonDelete->setText(QCoreApplication::translate("MainWindow", "\310\230terge Task", nullptr));
        pushButtonExport->setText(QCoreApplication::translate("MainWindow", "Export\304\203 XML", nullptr));
        pushButtonImport->setText(QCoreApplication::translate("MainWindow", "Import\304\203 XML", nullptr));
        comboBoxStyle->setItemText(0, QCoreApplication::translate("MainWindow", "Fusion", nullptr));
        comboBoxStyle->setItemText(1, QCoreApplication::translate("MainWindow", "Windows", nullptr));
        comboBoxStyle->setItemText(2, QCoreApplication::translate("MainWindow", "Macintosh", nullptr));
        comboBoxStyle->setItemText(3, QCoreApplication::translate("MainWindow", "Dark", nullptr));

        buttonStergeTot->setText(QCoreApplication::translate("MainWindow", "\310\230terge Tot", nullptr));
        menuTasks->setTitle(QCoreApplication::translate("MainWindow", "Tasks", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
