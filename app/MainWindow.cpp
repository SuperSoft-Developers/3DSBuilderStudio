#include "MainWindow.h"
#include "BuildSystem.h"

#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("3DS Builder Studio");
    resize(900, 600);

    QWidget *central = new QWidget(this);

    QVBoxLayout *layout = new QVBoxLayout(central);

    buildButton = new QPushButton("Build");
    console = new QTextEdit();

    console->setReadOnly(true);

    layout->addWidget(buildButton);
    layout->addWidget(console);

    connect(buildButton,
            &QPushButton::clicked,
            this,
            &MainWindow::buildProject);

    setCentralWidget(central);
}

void MainWindow::buildProject()
{
    BuildSystem build;

    QString output = build.build();

    console->append(output);
}
