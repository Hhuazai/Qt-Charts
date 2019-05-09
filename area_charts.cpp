#include "area_charts.h"

#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QDebug>

AreaChart::AreaChart(QWidget *parent) : QWidget(parent)
{
    series0 = new QLineSeries();
    series1 = new QLineSeries();
    chart = new QChart();

    *series0 << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6) << QPointF(9, 7) << QPointF(12, 6)
                   << QPointF(16, 7) << QPointF(18, 5);
    *series1 << QPointF(1, 3) << QPointF(3, 4) << QPointF(7, 3) << QPointF(8, 2) << QPointF(12, 3)
             << QPointF(16, 4) << QPointF(18, 3);

    series = new QAreaSeries(series0, series1);
    series->setName("Batman");
    QPen pen(0x059605);
    pen.setWidth(3);
    series->setPen(pen);

    chart->addSeries(series);
    chart->setTitle("Simple areachart example");
    chart->createDefaultAxes();
    chart->axisX()->setRange(0,20);
    chart->axisY()->setRange(0,10);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}

AreaChart::~AreaChart()
{
    qDebug() << QStringLiteral("析构函数--AreaChart");
}

QWidget *AreaChart::ShowView()
{
    return chartView;
}
