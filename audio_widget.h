#ifndef AUDIO_WIDGET_H
#define AUDIO_WIDGET_H

#include <QWidget>
#include <QtCharts/QChartGlobal>

QT_CHARTS_BEGIN_NAMESPACE
class QLineSeries;
class QChart;
class QChartView;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class QAudioInput;
class AudioXyseriesIODevice;

class AudioWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AudioWidget(QWidget *parent = 0);
    ~AudioWidget();

    QWidget *ShowView();

private:
    AudioXyseriesIODevice *m_device;
    QChart *m_chart;
    QLineSeries *m_series;
    QAudioInput *m_audioInput;
    QChartView *m_chartView;
};

#endif // AUDIO_WIDGET_H
