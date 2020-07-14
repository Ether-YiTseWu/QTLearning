#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set font size
    ui -> showData -> setFontPointSize(12);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // Set file path
    textPath = QFileDialog::getOpenFileName(this,tr("OpenFile"),"",tr("Text (*.txt)" ));

    // Read file
    QFile fileRead(textPath);
    if(fileRead.open(QIODevice::ReadOnly))
    {
        QTextStream input(&fileRead);
        input.setCodec("UTF-8");
        while(!input.atEnd())
        {
            QString line = input.readLine();
            ui -> showData -> append(line.toStdString().data());
        }
        fileRead.close();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui -> showData -> clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    // Write file
    QString userInput = ui -> input -> text();
    QFile fileWrite(textPath);
    if(fileWrite.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream output(&fileWrite);
        output << userInput << endl;
        fileWrite.close();
    }

    // Show User Input
    ui -> showData -> clear();
    QFile fileRead(textPath);
    if(fileRead.open(QIODevice::ReadOnly))
    {
        QTextStream input(&fileRead);
        input.setCodec("UTF-8");
        while(!input.atEnd())
        {
            QString line = input.readLine();
            ui -> showData -> append(line.toStdString().data());
        }
        fileRead.close();
    }
}
