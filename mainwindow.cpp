#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task.h"
#include <QDomDocument>
#include <QDomElement>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QStyleFactory>
#include <QSettings>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->buttonStergeTot, &QPushButton::clicked, this, &MainWindow::stergeToateTaskurile);

    ui->tableWidgetTasks->setColumnCount(4);
    ui->tableWidgetTasks->setHorizontalHeaderLabels(
        {"Titlu", "Descriere", "Data", "Finalizat"}
        );
    ui->comboBoxStyle->addItems(QStyleFactory::keys());
    ui->comboBoxStyle->addItem("Dark"); // adaugă tema dark
    QSettings settings("TaskTrackerCompany", "TaskTrackerApp");
    QString lastTheme = settings.value("lastTheme", "").toString();
    if (!lastTheme.isEmpty()) {
        int index = ui->comboBoxStyle->findText(lastTheme);
        if (index != -1) {
            ui->comboBoxStyle->setCurrentIndex(index);
            qApp->setStyle(QStyleFactory::create(lastTheme));
        }
    }

    lastFilePath = settings.value("lastFilePath", "").toString();

    QString savedTheme = settings.value("theme").toString();
    if (!savedTheme.isEmpty()) {
        qApp->setStyle(savedTheme);
        int index = ui->comboBoxStyle->findText(savedTheme);
        if (index != -1) {
            ui->comboBoxStyle->setCurrentIndex(index);
        }
    }

    QString lastFilePath = settings.value("lastFilePath").toString();
    if (!lastFilePath.isEmpty() && QFile::exists(lastFilePath)) {
        importFromXML(lastFilePath);


    }
}

MainWindow::~MainWindow()
{
    QSettings settings("TaskTrackerCompany", "TaskTrackerApp");
    settings.setValue("lastTheme", ui->comboBoxStyle->currentText());
    settings.setValue("lastFilePath", lastFilePath);

    settings.setValue("theme", ui->comboBoxStyle->currentText());

    settings.setValue("lastFilePath", lastFilePath);

    delete ui;
}

void MainWindow::updateTable() {
    ui->tableWidgetTasks->setColumnCount(4);
    QStringList headers;
    headers << "Titlu" << "Descriere" << "Data" << "Finalizat";
    ui->tableWidgetTasks->setHorizontalHeaderLabels(headers);

    ui->tableWidgetTasks->setRowCount(tasks.size());

    for (int i = 0; i < tasks.size(); ++i) {
        const Task &task = tasks[i];
        ui->tableWidgetTasks->setItem(i, 0, new QTableWidgetItem(task.getTitle()));
        ui->tableWidgetTasks->setItem(i, 1, new QTableWidgetItem(task.getDescription()));
        ui->tableWidgetTasks->setItem(i, 2, new QTableWidgetItem(task.getDueDate().toString("dd.MM.yyyy")));
        ui->tableWidgetTasks->setItem(i, 3, new QTableWidgetItem(task.isCompleted() ? "Da" : "Nu"));
    }

    ui->tableWidgetTasks->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetTasks->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_pushButtonAdd_clicked() {
    QString title = ui->lineEditTitle->text();
    QString description = ui->lineEditDescription->text();
    QDate dueDate = ui->dateEditDueDate->date();
    bool completed = ui->checkBoxCompleted->isChecked();

    if (title.isEmpty()) return;

    Task task(title, description, dueDate, completed);
    tasks.append(task);

    updateTable();
}


void MainWindow::on_pushButtonDelete_clicked() {
    int row = ui->tableWidgetTasks->currentRow();

    if (row < 0 || row >= tasks.size()) {
        return;
    }

    tasks.removeAt(row);
    updateTable();
}

void MainWindow::exportToXML(const QString& fileName) {
    QDomDocument doc("TaskList");
    QDomElement root = doc.createElement("Tasks");
    doc.appendChild(root);

    for (const Task &task : tasks) {
        QDomElement taskElement = doc.createElement("Task");

        QDomElement title = doc.createElement("Titlu");
        title.appendChild(doc.createTextNode(task.getTitle()));
        taskElement.appendChild(title);

        QDomElement description = doc.createElement("Descriere");
        description.appendChild(doc.createTextNode(task.getDescription()));
        taskElement.appendChild(description);

        QDomElement dueDate = doc.createElement("Data");
        dueDate.appendChild(doc.createTextNode(task.getDueDate().toString(Qt::ISODate)));
        taskElement.appendChild(dueDate);

        QDomElement completed = doc.createElement("Finalizat");
        completed.appendChild(doc.createTextNode(task.isCompleted() ? "Da" : "Nu"));
        taskElement.appendChild(completed);

        root.appendChild(taskElement);
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Nu pot deschide fișierul pentru scriere";
        return;
    }

    QTextStream stream(&file);
    stream << doc.toString();
    file.close();
}

void MainWindow::importFromXML(const QString& fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Nu pot deschide fișierul pentru citire";
        return;
    }

    QDomDocument doc;
    if (!doc.setContent(&file)) {
        file.close();
        qDebug() << "Nu pot interpreta XML-ul";
        return;
    }
    file.close();

    tasks.clear();

    QDomElement root = doc.documentElement();
    QDomNodeList taskNodes = root.elementsByTagName("Task");

    for (int i = 0; i < taskNodes.count(); ++i) {
        QDomNode node = taskNodes.at(i);
        if (node.isElement()) {
            QDomElement e = node.toElement();

            QString title = e.firstChildElement("Titlu").text();
            QString description = e.firstChildElement("Descriere").text();
            QDate dueDate = QDate::fromString(e.firstChildElement("Data").text(), Qt::ISODate);
            bool completed = (e.firstChildElement("Finalizat").text() == "Da");

            Task task(title, description, dueDate, completed);
            tasks.append(task);
        }
    }

    updateTable();
}

void MainWindow::on_pushButtonExport_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Salvează XML", "", "XML Files (*.xml)");
    if (!fileName.isEmpty()) {
        exportToXML(fileName);
        lastFilePath = fileName;
    }
}

void MainWindow::on_pushButtonImport_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Deschide XML", "", "XML Files (*.xml)");
    if (!fileName.isEmpty()) {
        importFromXML(fileName);
        lastFilePath = fileName;
    }
}

void MainWindow::on_comboBoxStyle_currentIndexChanged(const QString &styleName) {
    if (styleName == "Dark") {
        QFile file(":/styles/darktheme.qss");
        if (file.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream stream(&file);
            qApp->setStyleSheet(stream.readAll());
        }
    } else {
        qApp->setStyle(QStyleFactory::create(styleName));
        qApp->setStyleSheet("");
    }
}

void MainWindow::stergeToateTaskurile()
{
    if (QMessageBox::question(this, "Confirmare", "Sigur dorești să ștergi toate task-urile?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    {
        ui->tableWidgetTasks->setRowCount(0);
    }
}
