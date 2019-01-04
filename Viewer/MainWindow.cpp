#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "DisplayScene.h"

#include <QGLWidget>
#include <QSurfaceFormat>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    displayScene = new DisplayScene(this);
    ui->graphicsView->setScene(displayScene);
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->rect());
}

MainWindow::~MainWindow()
{
    delete displayScene;
    delete ui;
}
