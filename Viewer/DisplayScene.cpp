#include "DisplayScene.h"

#include <iostream>

#include <QOpenGLFunctions>
#include <QPaintEngine>

DisplayScene::DisplayScene(QWidget *parent):
    QGraphicsScene()
{
    QGraphicsTextItem * mTextItem = new QGraphicsTextItem("Sample Text");
//    mTextItem->setTextInteractionFlags(Qt::TextEditorInteraction);
    mTextItem->setDefaultTextColor(QColor(200, 0, 0, 255));
    addItem(mTextItem);
    mTextItem->setPos(sceneRect().width()/2, sceneRect().height()/2);

//    mTextItem->setFlag(QGraphicsItem::ItemIsSelectable);
//    mTextItem->setFlag(QGraphicsItem::ItemIsFocusable);
    mTextItem->setFlag(QGraphicsItem::ItemIsMovable);
}

void DisplayScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    initializeOpenGLFunctions();
    painter->beginNativePainting();
    glClearColor(0.45f, 0.46f, 0.47f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    painter->endNativePainting();
}
