#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QImage>
#include <QtMath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void drawImage();

    void on_pushButton_clicked();

protected:
    void paintEvent(QPaintEvent *); //переопределяем событие обновления изображения

private:
    Ui::MainWindow *ui;
    bool fl_draw = false; //переключатель рисовать или нет линию
};
#endif // MAINWINDOW_H
