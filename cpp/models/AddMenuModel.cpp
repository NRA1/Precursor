#include "AddMenuModel.h"
#include "cpp/ViewModel.h"

AddMenuModel::AddMenuModel() : x_(0), y_(0), visible_(false)
{
}

void AddMenuModel::open(int x, int y)
{
    x_ = x;
    emit xChanged();
    y_ = y;
    emit yChanged();
    visible_ = true;
    emit visibleChanged();
}

void AddMenuModel::focusLost()
{
    visible_ = false;
    emit visibleChanged();
    y_ = 0;
    emit yChanged();
    x_ = 0;
    emit xChanged();
}

int AddMenuModel::x() const
{
    return x_;
}

void AddMenuModel::setX(int x)
{
    x_ = x;
    emit xChanged();
}

int AddMenuModel::y() const
{
    return y_;
}

void AddMenuModel::setY(int y)
{
    y_ = y;
    emit yChanged();
}

bool AddMenuModel::visible() const
{
    return visible_;
}

void AddMenuModel::setVisible(bool visible)
{
    visible_ = visible;
    emit visibleChanged();
}

