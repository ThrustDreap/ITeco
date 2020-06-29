#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    inputLabel = new QLabel(tr("Input path"));
    outputLabel = new QLabel(tr("Output path"));

    inputPathLine = new QLineEdit;
    inputLabel->setBuddy(inputPathLine);

    outputPathLine = new QLineEdit;
    outputLabel->setBuddy(outputPathLine);

    findInputButton = new QPushButton(tr("Choose..."));
    findInputButton->setDefault(true);
    connect(findInputButton, SIGNAL(clicked()), this, SLOT(inputButtonClicked()));

    findOutputButton = new QPushButton(tr("Choose..."));
    connect(findOutputButton, SIGNAL(clicked()), this, SLOT(outputButtonClicked()));

    startButton = new QPushButton(tr("Start"));
    startButton->setEnabled(false);

    QHBoxLayout* inputHBox = static_cast<QHBoxLayout*>(createLayout(new QHBoxLayout(), inputLabel, inputPathLine));
    QHBoxLayout* outputHBox = static_cast<QHBoxLayout*>(createLayout(new QHBoxLayout(), outputLabel, outputPathLine));
    QVBoxLayout * buttonsVBox = static_cast<QVBoxLayout*>(createLayout(new QVBoxLayout(), findInputButton, findOutputButton));

    QVBoxLayout * lines = new QVBoxLayout();
    lines->addLayout(inputHBox);
    lines->addLayout(outputHBox);

    QHBoxLayout * main = new QHBoxLayout();
    main->addLayout(lines);
    main->addLayout(buttonsVBox);

    //this->setLayout(inputHBox);
    this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inputButtonClicked()
{
    //QString Directory = QDir::
}

void MainWindow::outputButtonClicked()
{

}

void MainWindow::startButtonClicked()
{

}

QLayout *MainWindow::createLayout(QLayout *layout, QWidget *w1, QWidget *w2){
    layout->addWidget(w1);
    layout->addWidget(w2);
    return layout;
}

