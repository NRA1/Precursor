#ifndef PRECURSOR_SIZE_H
#define PRECURSOR_SIZE_H


#include <QObject>

class Size : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)

public:
    Size(int width, int height, QObject *parent = nullptr);
    Size(QObject *parent = nullptr);

    int width() const;
    void setWidth(int width);
    int height() const;
    void setHeight(int height);

signals:
    void widthChanged();
    void heightChanged();

private:
    int width_ = 0;
    int height_ = 0;
};


#endif //PRECURSOR_SIZE_H
