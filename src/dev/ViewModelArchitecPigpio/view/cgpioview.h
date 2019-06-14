#ifndef CGPIOVIEW_H
#define CGPIOVIEW_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QAbstractItemView>

class CGpioView : public QAbstractItemView
{
    Q_OBJECT

public:
    explicit CGpioView(QWidget *parent = nullptr);

    QRect visualRect(const QModelIndex &index) const override;
    void scrollTo(const QModelIndex &index, ScrollHint hint) override;
    QModelIndex indexAt(const QPoint &point) const override;

    void updateView(const QModelIndex &index, const QVariant &variant);

protected slots:
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int>());

protected:
    QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers) override;
    int horizontalOffset() const override;
    int verticalOffset() const override;
    bool isIndexHidden(const QModelIndex &index) const override;
    void setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags command) override;
    QRegion visualRegionForSelection(const QItemSelection &selection) const override;

protected:
    QLabel *mLabel;

};

#endif // CGPIOVIEW_H
