#include "audio_xyseriesiodevice.h"

#include <QtCharts/QXYSeries>

AudioXyseriesIODevice::AudioXyseriesIODevice(QXYSeries *series, QObject *parent) :
    QIODevice(parent),
    m_series(series)
{

}

qint64 AudioXyseriesIODevice::readData(char *data, qint64 maxlen)
{
    Q_UNUSED(data);
    Q_UNUSED(maxlen);
    return -1;
}

qint64 AudioXyseriesIODevice::writeData(const char *data, qint64 len)
{
    qint64 range = 2000;
    QVector<QPointF> oldPoints = m_series->pointsVector();
    QVector<QPointF> points;
    int resolution = 4;

    if (oldPoints.count() < range) {
        points = m_series->pointsVector();
    } else {
        for (int i = len/resolution; i < oldPoints.count(); i++)
            points.append(QPointF(i - len/resolution, oldPoints.at(i).y()));
    }

    qint64 size = points.count();
    for (int k = 0; k < len/resolution; k++)
        points.append(QPointF(k + size, ((quint8)data[resolution * k] - 128)/128.0));

    m_series->replace(points);
    return len;
}
