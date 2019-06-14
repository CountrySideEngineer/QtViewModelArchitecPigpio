#include <QThread>
#include "cgpioview.h"

/**
 * @brief CGpioView::CGpioView  Constructor
 * @param parent    Pointer to parental object.
 */
CGpioView::CGpioView(QWidget *parent) : QAbstractItemView (parent)
{
    this->mLabel = new QLabel(this);
    this->mLabel->resize(150, 30);
    this->mLabel->setText("Init");

}

QRect CGpioView::visualRect(const QModelIndex &index) const
{
    Q_UNUSED(index);

    return QRect(0, 0, 300, 300);
}

void CGpioView::scrollTo(const QModelIndex &index, ScrollHint hint)
{
    Q_UNUSED(index);
    Q_UNUSED(hint);
}

QModelIndex CGpioView::indexAt(const QPoint &point) const
{
    Q_UNUSED(point);

    return QModelIndex();
}

void CGpioView::updateView(const QModelIndex &index, const QVariant &variant)
{
    Q_UNUSED(index);

    int variantValue = variant.toInt();

    if (0 == variantValue) {
        this->mLabel->setText("LOW");
    } else {
        this->mLabel->setText("HIGH");
    }
    printf("updateView() called : ThreadID = %d\r\n", (int)QThread::currentThreadId());
}

void CGpioView::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
{
    Q_UNUSED(topLeft);
    Q_UNUSED(bottomRight);
    Q_UNUSED(roles);

    this->updateView(topLeft, model()->data(topLeft));
}

QModelIndex CGpioView::moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers)
{
    Q_UNUSED(cursorAction);
    Q_UNUSED(modifiers);

    return QModelIndex();
}

int CGpioView::horizontalOffset() const
{
    return 0;
}

int CGpioView::verticalOffset() const
{
    return 0;
}

bool CGpioView::isIndexHidden(const QModelIndex &index) const
{
    Q_UNUSED(index);

    return false;
}

void CGpioView::setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags command)
{
    Q_UNUSED(rect);
    Q_UNUSED(command);
}

QRegion CGpioView::visualRegionForSelection(const QItemSelection &selection) const
{
    Q_UNUSED(selection);

    return QRegion();
}
