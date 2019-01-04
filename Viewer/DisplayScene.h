#ifndef DISPLAYSCENE_H
#define DISPLAYSCENE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QOpenGLFunctions>

class DisplayScene : public QGraphicsScene, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    DisplayScene(QWidget * parent = 0);

protected:
    virtual void drawBackground(QPainter *_painter, const QRectF &_rect);
};

#endif // DISPLAYSCENE_H
