#include <QThread>
#include "cgpiomodel.h"

/**
 * @brief CGpioModel::CGpioModel    Copy constructor
 * @param parent    Pointer to QObject holds this one.
 */
CGpioModel::CGpioModel(QObject* parent) : QAbstractItemModel (parent) {}

/**
 * @brief CGpioModel::index Returns QModelIndex object
 * @param row       Row No. of QModelIndex
 * @param column    Column No. of QModelIndex.
 * @param parent    NOT IN USE.
 * @return  QModelIndex created depends on the arguments row and column.
 */
QModelIndex CGpioModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return createIndex(row, column);
}

/**
 * @brief CGpioModel::parent    Return QModelIndex.
 * @param child     NOT IN USE.
 * @return  QModelIndex object.
 */
QModelIndex CGpioModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);

    return QModelIndex();
}

/**
 * @brief CGpioModel::rowCount  Returns the number of row in model map.
 * @param parent    NOT IN USE.
 * @return  Returns 1
 */
int CGpioModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return 1;
}

/**
 * @brief CGpioModel::columnCount   Returns the number of column in model map.
 * @param parent    NOT IN USE
 * @return  Returns 1
 */
int CGpioModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return 1;
}

/**
 * @brief CGpioModel::data
 * @param index
 * @param role
 * @return
 */
QVariant CGpioModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role);

    if (index.isValid()) {
        return mData[index];
    } else {
        return QVariant();
    }
}

bool CGpioModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(role);

    printf("CGpioModel::setData called : ThreadId = %d\r\n", (int)QThread::currentThreadId());

    if (index.isValid()) {
        this->mData[index] = value;
        emit dataChanged(index, index);

        return true;
    } else {
        return false;
    }
}

void CGpioModel::setGpioData(int pinNo, int pinData)
{
    this->setData(index(pinNo, 0), QVariant(pinData));
}
