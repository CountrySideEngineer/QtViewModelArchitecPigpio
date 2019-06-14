#ifndef CGPIOMODEL_H
#define CGPIOMODEL_H

#include <QAbstractItemModel>
#include <QObject>

class CGpioModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit CGpioModel(QObject* parent = nullptr);

    //Implement abstracted method of super class.
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    //original method.
    void setGpioData(int pinNo, int pinData);

protected:
    QMap<QModelIndex, QVariant> mData;
};

#endif // CGPIOMODEL_H
