#ifndef SCATTERCHART_H
#define SCATTERCHART_H

#include <QWidget>
#include <QtCharts/QChartGlobal>

QT_CHARTS_BEGIN_NAMESPACE
class QScatterSeries;
class QChart;
class QChartView;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class ScatterChart : public QWidget
{
    Q_OBJECT
public:
    explicit ScatterChart(QWidget *parent = 0);
    ~ScatterChart();

    QWidget *ShowView();

private:
    QScatterSeries *series;
    QChart *chart;
    QChartView *chartView;
};

#endif // SCATTERCHART_H
