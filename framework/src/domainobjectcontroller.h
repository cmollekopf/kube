/*
    Copyright (c) 2018 Christian Mollekopf <mollekopf@kolabsys.com>

    This library is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This library is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to the
    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301, USA.
*/
#pragma once

#include <QObject>
#include <QVariant>
#include <QAbstractItemModel>
#include <QSharedPointer>

namespace Kube {

class DomainObjectController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant currentObject READ currentObject NOTIFY currentObjectChanged)
public:
    explicit DomainObjectController(QObject *parent = 0);

    QVariant currentObject() const;

    Q_INVOKABLE void create(const QVariantMap &object);
    Q_INVOKABLE void monitor(const QVariant &object);

signals:
    void currentObjectChanged();

private:
    QVariant mCurrentObject;
    QSharedPointer<QAbstractItemModel> mModel;
};

}
