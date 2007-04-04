/****************************************************************************
**
** Copyright (C) Qxt Foundation. Some rights reserved.
**
** This file is part of the QxtCore module of the Qt eXTension library
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or any later version.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** There is aditional information in the LICENSE file of libqxt.
** If you did not receive a copy of the file try to download it or
** contact the libqxt Management
** 
** <http://libqxt.sourceforge.net>  <aep@exys.org>
**
****************************************************************************/
#ifndef QXTCSVMODEL_H
#define QXTCSVMODEL_H

#include <QAbstractTableModel>
#include <QVariant>
#include <QIODevice>
#include <QChar>
#include <QString>
#include <QStringList>
#include <QModelIndex>
#include <QxtPimpl.h>

/**
@author Adam Higerd
*/
class QxtCsvModelPrivate;
class QxtCsvModel : public QAbstractTableModel
{
Q_OBJECT
public:
    QxtCsvModel(QObject *parent = 0);
    QxtCsvModel(QIODevice *file, QObject *parent = 0, bool withHeader = false, QChar separator = ',');
    QxtCsvModel(const QString filename, QObject *parent = 0, bool withHeader = false, QChar separator = ',');
    ~QxtCsvModel();

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex& index, const QVariant& data, int role = Qt::EditRole);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    void setHeaderData(const QStringList data);

    bool insertRow(int row, const QModelIndex& parent = QModelIndex());
    bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex());
    bool removeRow(int row, const QModelIndex& parent = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex());
    bool insertColumn(int col, const QModelIndex& parent = QModelIndex());
    bool insertColumns(int col, int count, const QModelIndex& parent = QModelIndex());
    bool removeColumn(int col, const QModelIndex& parent = QModelIndex());
    bool removeColumns(int col, int count, const QModelIndex& parent = QModelIndex());

    void setSource(QIODevice *file, bool withHeader = false, QChar separator = ',');
    void setSource(const QString filename, bool withHeader = false, QChar separator = ',');

    void toCSV(QIODevice *file, bool withHeader = false, QChar separator = ',');
    void toCSV(const QString filename, bool withHeader = false, QChar separator = ',');

    Qt::ItemFlags flags(const QModelIndex& index) const;

private:
    QXT_DECLARE_PRIVATE(QxtCsvModel);
};

#endif
