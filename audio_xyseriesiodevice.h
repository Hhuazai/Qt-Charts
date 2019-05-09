#ifndef AUDIO_XYSERIESIODEVICE_H
#define AUDIO_XYSERIESIODEVICE_H

#include <QtCore/QIODevice>
#include <QtCharts/QChartGlobal>

QT_CHARTS_BEGIN_NAMESPACE
class QXYSeries;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class AudioXyseriesIODevice : public QIODevice
{
public:
    explicit AudioXyseriesIODevice(QXYSeries * series, QObject *parent = 0);

protected:
    //对QIODevice进行子类化，您可以为自己的输入输出设备提供相同的接口。
    //QIODevice的子类只需要实现protected的readData()和writeData()函数。
    //QIODevice使用这些函数来实现其所有方便的功能，例如getChar()、readLine()和write()。
    qint64 readData(char *data, qint64 maxlen);
    qint64 writeData(const char *data, qint64 len);

private:
      QXYSeries *m_series;
};

#endif // AUDIO_XYSERIESIODEVICE_H
