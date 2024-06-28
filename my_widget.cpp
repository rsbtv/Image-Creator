#include "my_widget.h"

my_widget::my_widget(QWidget *parent) : QWidget(parent)
{
    im = QImage(1150,570, QImage::Format_ARGB32_Premultiplied);
}


void my_widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(0,0,im);
}
