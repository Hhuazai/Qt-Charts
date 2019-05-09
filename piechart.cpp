#include "piechart.h"

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QDebug>

PieChart::PieChart(QWidget *parent) : QWidget(parent)
{
    series = new QPieSeries;

    series->append("Jane",    1);
    series->append("Joe",     2);
    series->append("Andy",    3);
    series->append("Barbara", 4);
    series->append("Axel",    5);

    QPieSlice *slice = series->slices().at(1);
    slice->setExploded();
    slice->setLabelVisible();
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);

    chart = new QChart;
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Pie chart");

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}

PieChart::~PieChart()
{
    qDebug() << QStringLiteral("析构函数--PieChart");
}

QWidget *PieChart::ShowView()
{
    return chartView;
}
