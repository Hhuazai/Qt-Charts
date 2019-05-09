#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class AreaChart;
class BarChart;
class AudioWidget;
class MultiAxis;
class LineChart;
class PieChart;
class SplineChart;
class ScatterChart;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void ShowDemo_1();
    void ShowDemo_2();
    void ShowDemo_3();
    void ShowDemo_4();
    void ShowDemo_5();

    void ShowAreaChart();
    void ShowBarChart();
    void ShowLineChart();
    void ShowPieChart();
    void ShowSplineChart();
    void ShowScatterChart();

private:
    Ui::MainWindow *ui;

    AreaChart *areaChart;
    BarChart *barChart;
    LineChart *lineChart;
    PieChart *pieChart;
    SplineChart *splineChart;
    ScatterChart *scatterChart;

    AudioWidget *audio;
    MultiAxis *multiAxis;

};

#endif // MAINWINDOW_H
