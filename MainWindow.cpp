#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "area_charts.h"
#include "BarChart.h"
#include "audio_widget.h"
#include "multiaxis.h"
#include "linechart.h"
#include "piechart.h"
#include "splinechart.h"
#include "scatterchart.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    areaChart(0),
    barChart(0),
    lineChart(0),
    pieChart(0),
    splineChart(0),
    scatterChart(0),
    audio(0),
    multiAxis(0)
{
    ui->setupUi(this);

    QMenu *menu1 = new QMenu("DEMO");
    QAction *action1 = new QAction("Audio");
    QAction *action2 = new QAction("MultiAxis");
//    QAction *action3 = new QAction("Demo 3");
//    QAction *action4 = new QAction("Demo 4");
//    QAction *action5 = new QAction("Demo 5");

    menu1->addAction(action1);
    menu1->addAction(action2);
//    menu1->addAction(action3);
//    menu1->addAction(action4);
//    menu1->addAction(action5);

    QMenu *menu2 = new QMenu("CHARTS");
    QAction *action6  = new QAction("Area chart(区域图)");
    QAction *action7  = new QAction("Bar chart(条形图)");
    QAction *action8  = new QAction("Line chart(折线图)");
    QAction *action9  = new QAction("Pie chart(饼状图)");
    QAction *action10 = new QAction("Spline chart(曲线图)");
    QAction *action11 = new QAction("Scatter chart(散点图)");

    menu2->addAction(action6);
    menu2->addAction(action7);
    menu2->addAction(action8);
    menu2->addAction(action9);
    menu2->addAction(action10);
    menu2->addAction(action11);

    connect(action1  , &QAction::triggered, this, &MainWindow::ShowDemo_1);
    connect(action2  , &QAction::triggered, this, &MainWindow::ShowDemo_2);
//    connect(action3  , &QAction::triggered, this, &MainWindow::ShowDemo_3);
//    connect(action4  , &QAction::triggered, this, &MainWindow::ShowDemo_4);
//    connect(action5  , &QAction::triggered, this, &MainWindow::ShowDemo_5);
    connect(action6  , &QAction::triggered, this, &MainWindow::ShowAreaChart);
    connect(action7  , &QAction::triggered, this, &MainWindow::ShowBarChart);
    connect(action8  , &QAction::triggered, this, &MainWindow::ShowLineChart);
    connect(action9  , &QAction::triggered, this, &MainWindow::ShowPieChart);
    connect(action10 , &QAction::triggered, this, &MainWindow::ShowSplineChart);
    connect(action11 , &QAction::triggered, this, &MainWindow::ShowScatterChart);

    menuBar()->addMenu(menu1);
    menuBar()->addMenu(menu2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowDemo_1()
{
    if (audio == NULL)
    {
        audio = new AudioWidget(this);
    }
    this->takeCentralWidget()->close();
    this->setCentralWidget(audio->ShowView());
}

void MainWindow::ShowDemo_2()
{
    if (multiAxis == NULL)
    {
        multiAxis = new MultiAxis(this);
    }
    this->takeCentralWidget()->close();
    this->setCentralWidget(multiAxis->ShowView());
}

void MainWindow::ShowDemo_3()
{

}

void MainWindow::ShowDemo_4()
{

}

void MainWindow::ShowDemo_5()
{

}

void MainWindow::ShowAreaChart()
{
    if (areaChart == NULL)
    {
        areaChart = new AreaChart(this);
    }
    this->takeCentralWidget()->close();
    this->setCentralWidget(areaChart->ShowView());
}

void MainWindow::ShowBarChart()
{
    if (barChart == NULL)
    {
        barChart = new BarChart(this);
    }
    this->takeCentralWidget()->close();
    this->setCentralWidget(barChart->ShowView());
}

void MainWindow::ShowLineChart()
{
    if (lineChart == NULL)
    {
        lineChart = new LineChart(this);
    }
    this->takeCentralWidget()->close();
    this->setCentralWidget(lineChart->ShowView());
}

void MainWindow::ShowPieChart()
{
    if (pieChart == NULL)
    {
        pieChart = new PieChart(this);
    }
    this->takeCentralWidget()->close();
    this->setCentralWidget(pieChart->ShowView());
}

void MainWindow::ShowSplineChart()
{
    if (splineChart == NULL)
    {
        splineChart = new SplineChart(this);
    }
    this->takeCentralWidget()->close();
    this->setCentralWidget(splineChart->ShowView());
}

void MainWindow::ShowScatterChart()
{
    if (scatterChart == NULL)
    {
        scatterChart = new ScatterChart(this);
    }
    this->takeCentralWidget()->close();
    this->setCentralWidget(scatterChart->ShowView());
}
