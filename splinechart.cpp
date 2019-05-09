#include "splinechart.h"

#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QDebug>

SplineChart::SplineChart(QWidget *parent) : QWidget(parent)
{
    series = new QSplineSeries();
    series->setName("spline");

    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Spline chart");
    chart->createDefaultAxes();
    chart->axisY()->setRange(0, 10);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}

SplineChart::~SplineChart()
{
    qDebug() << QStringLiteral("析构函数--SplineChart");
}

QWidget *SplineChart::ShowView()
{
    return chartView;
}
