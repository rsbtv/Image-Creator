#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) //конструктор
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fl_draw = false; //линии исходно нет
    drawImage();
}

MainWindow::~MainWindow() //деструктор
{
    delete ui;
}



void MainWindow::paintEvent(QPaintEvent *) //переопределенный обработчик рисования
{
    if (fl_draw)
    {
        QPainter painter(this); //наш художник, привязанный к форме
    }
}

void MainWindow::drawImage() //рисование через заранее подготовленное изображение
{
    QPainter painter(&ui->widget->im);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(3);

    QPen background_pen;
    background_pen.setColor(QColor(240,240,240));
    background_pen.setWidth(0);

    QBrush moon;
    moon.setColor(QColor(255, 255, 224));
    moon.setStyle(Qt::SolidPattern);

    QBrush grass;
    grass.setColor(QColor(166, 180, 116));
    grass.setStyle(Qt::SolidPattern);

    QBrush wall;
    wall.setColor(QColor(233, 121, 80));
    wall.setStyle(Qt::SolidPattern);

    QBrush roof;
    roof.setColor(QColor(186, 41, 65));
    roof.setStyle(Qt::SolidPattern);

    QBrush window;
    window.setColor(QColor(109, 207, 168));
    window.setStyle(Qt::SolidPattern);

    QBrush frame;
    frame.setColor(QColor(230, 232, 223));
    frame.setStyle(Qt::SolidPattern);

    QBrush door;
    door.setColor(QColor(199, 136, 68));
    door.setStyle(Qt::SolidPattern);

    QBrush background;
    background.setColor(QColor(240,240,240));
    background.setStyle(Qt::SolidPattern);

    QBrush crater;
    crater.setColor(QColor(143, 141, 153));
    crater.setStyle(Qt::SolidPattern);

    //небо
    QRadialGradient radialGrad(QPointF(1000,80), 100);
    radialGrad.setColorAt(0, QColor(97, 118, 182));
    radialGrad.setColorAt(0.5, QColor(100, 84, 178));
    radialGrad.setColorAt(1, QColor(34, 32, 86));
    painter.setBrush(radialGrad);
    painter.drawRect(0,0,1160,670);

    //крыша-параллелограмм
    static const QPointF right_roof_points[4] = {
        QPointF(360,315),
        QPointF(320,201),
        QPointF(671, 201),
        QPointF(741, 315)
    };
    painter.setBrush(roof);
    painter.setPen(pen);
    painter.drawPolygon(right_roof_points, 4);
    //левая стена
    painter.setBrush(wall);
    painter.drawRect(180,265,200,250);

    //правая стена
    painter.setBrush(wall);
    painter.drawRect(381,315,330,200);

    //треугольник
    static const QPointF triangle_points[3] = {
        QPointF(180, 265), //левая точка
        QPointF(280, 141), //вершина
        QPointF(380, 265), //правая точка
    };
    painter.setBrush(wall);
    painter.drawPolygon(triangle_points, 3);

    //крыша 6-угольная
    static const QPointF left_roof_points[6] = {
        QPointF(150, 295), //левая нижняя
        QPointF(135, 285), //левая верхняя
        QPointF(280, 141), //средняя верхняя
        QPointF(425, 285), //правая верхняя
        QPointF(410, 295), //правая нижняя
        QPointF(280, 165), //средняя нижняя
    };
    painter.setBrush(roof);
    painter.drawPolygon(left_roof_points,6);

    //окно верхнее
    painter.setBrush(window);
    painter.drawRect(255, 201, 50, 50);
    painter.drawLine(280, 201, 280, 251);
    painter.drawLine(255, 226, 305, 226);

    //рама левая
    painter.setBrush(frame);
    painter.drawRect(202, 360, 160, 100);

    //рама правая
    painter.setBrush(frame);
    painter.drawRect(560, 360, 120, 100);

    //окно правое
    painter.setBrush(window);
    painter.drawRect(565, 365, 110, 90);
    painter.drawLine(620, 365, 620, 455);
    painter.drawLine(565, 410, 675, 410);

    //окно левое
    painter.setBrush(window);
    painter.drawRect(207, 365, 150, 90);
    painter.drawLine(282, 365, 282, 455);
    painter.drawLine(207, 410, 357, 410);

    //порог
    painter.setBrush(wall);
    painter.drawRect(420, 505, 100, 20);

    //дверь
    painter.setBrush(door);
    painter.drawRect(430, 355, 80, 150);

    //ручка
    painter.setBrush(frame);
    QPoint handle(440, 430);
    painter.drawEllipse(handle, 5,5);

    //луна и кратеры
    painter.setPen(background_pen);
    painter.setBrush(moon);

    QPoint moon_im(1000,80);
    painter.drawEllipse(moon_im, 40,40);

    painter.setBrush(crater);
    QPoint moon_crater_1(973, 100);
    painter.drawEllipse(moon_crater_1, 6,6);

    QPoint moon_crater_2(983, 98);
    painter.drawEllipse(moon_crater_2, 4,6);

    QPoint moon_crater_3(1027, 70);
    painter.drawEllipse(moon_crater_3, 9,7);

    QPoint moon_crater_4(976, 77);
    painter.drawEllipse(moon_crater_4, 8,6);

    QPoint moon_crater_5(987, 65);
    painter.drawEllipse(moon_crater_5, 7,4);

    QPoint moon_crater_6(1020, 99);
    painter.drawEllipse(moon_crater_6, 8,6);

    QPoint moon_crater_7(999, 104);
    painter.drawEllipse(moon_crater_7, 5,7);

    QPoint moon_crater_8(1005, 60);
    painter.drawEllipse(moon_crater_8, 5,5);


    QPoint moon_crater_9(999, 79);
    painter.drawEllipse(moon_crater_9, 9,7);


    //трава
    grass.setColor(QColor(166, 180, 116));
    grass.setStyle(Qt::SolidPattern);

    painter.setPen(pen);
    painter.setBrush(grass);
    painter.drawRect(0,515,1100,50);
    repaint();
}

void MainWindow::on_pushButton_clicked()
{
    QPainter painter(&ui->widget->im);
    QPen pen;
    pen.setColor(Qt::white);
    pen.setWidth(1);
    QBrush star_brush;
    star_brush.setColor(Qt::white);
    star_brush.setStyle(Qt::SolidPattern);
    painter.setBrush(star_brush);
    bool flag;
    int number = ui->lineEdit->text().toInt(&flag);
    int r = 4;
    if (flag && number>0)
    {
        for(int i = 0; i < number; i++)//функция рисования звёзд
        {

            int x;
            int y;
            y = rand() %510-0;
            x = rand() %1100-0;
            if (
                    (
                        //обход крыши
                        ((1.0*x + y < 414)
                        or ((-1.1*x + 1.094*y < -159) and (y<197)))

                        //под и за крышей справа
                        or (x>745)
                        or ((x>716) and (y>317))
                        or ((-1.85*x + y < -1060))

                        //слева под крышей
                        or ((-0.5*x + y > 221) and (x<174))
                        or ((1.1*x + y > 465) and (x<173) and (y>265))
                    )

                    //обход луны
                    and ((pow(x - 1000,2) + pow(y - 80,2)) > 2000)
               )
            {
                QPoint point(x,y);
                painter.drawEllipse(point, r, r/4);
                painter.drawEllipse(point, r/4,r);
                repaint();
            }
            else
                i--;


        }
    }
    else
    {
       QMessageBox::information(this, "Ошибка", "Введите положительное число", QMessageBox::Ok);
       flag = false;
    }

}






