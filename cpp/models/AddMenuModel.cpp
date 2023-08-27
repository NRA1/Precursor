#include "AddMenuModel.h"
#include "cpp/ViewModel.h"

AddMenuModel::AddMenuModel() : x(0), y(0), visible(false)
{
}

void AddMenuModel::open(int x, int y)
{
    x = x;
    emit xChanged();
    y = y;
    emit yChanged();
    visible = true;
    emit visibleChanged();
}

void AddMenuModel::focusLost()
{
    visible = false;
    emit visibleChanged();
    y = 0;
    emit yChanged();
    x = 0;
    emit xChanged();
}

