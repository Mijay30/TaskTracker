#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "task.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonDelete_clicked();

private:
    Ui::MainWindow *ui;
    QVector<Task> tasks;
    void updateTable();

private:
    void exportToXML(const QString& fileName);
    void importFromXML(const QString& fileName);

private slots:
    void on_pushButtonExport_clicked();
    void on_pushButtonImport_clicked();

private slots:
    void on_comboBoxStyle_currentIndexChanged(const QString &styleName);

private:
    QString lastFilePath;

private:
    void stergeToateTaskurile();
};

#endif
