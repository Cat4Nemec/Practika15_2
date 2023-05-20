#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPen penRed(Qt::red, 6, Qt::SolidLine);
    QBrush brushWhite(Qt::white, Qt::SolidPattern);
    QBrush brushBlack(Qt::black, Qt::SolidPattern);

    painter.setPen(penRed);
    painter.setBrush(brushWhite);
    painter.drawRect(100, 100, 140, 140);

    for (int i = 0;i < 8;i++) {
        painter.drawRect(100 + i * (140 + 20), 100, 140, 140);
    }
}
mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    void paintEvent(QPaintEvent* event);
};

#endif // MAINWINDOW_H
