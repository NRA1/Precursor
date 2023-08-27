#ifndef PRECURSOR_PROPERTYVALUEPATH_H
#define PRECURSOR_PROPERTYVALUEPATH_H


#include "Path.h"

class PropertyValuePath : public Path
{
public:
    PropertyValuePath(QObject *parent = nullptr);

    void resize(const QSizeF &size) override;

private:
    QSizeF base_size_;
};


#endif //PRECURSOR_PROPERTYVALUEPATH_H
