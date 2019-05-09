#ifndef SPLINECHART_H
#define SPLINECHART_H

#include <QWidget>
#include <QtCharts/QChartGlobal>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QChart;
class QChartView;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class SplineChart : public QWidget
{
    Q_OBJECT
public:
    explicit SplineChart(QWidget *parent = 0);
    ~SplineChart();

    QWidget *ShowView();

private:
    QSplineSeries *series;
    QChart *chart;
    QChartView *chartView;
};

#endif // SPLINECHART_H
