// Copyright (c) 2015-2018, The Bytecoin developers
// Copyright (c) 2018, The PinkstarcoinV2 developers
// Copyright (c) 2018, The Bittorium developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <QDateTime>
#include <QSortFilterProxyModel>

namespace WalletGui {

class ICryptoNoteAdapter;

class FilteredBlockModel : public QSortFilterProxyModel {
  Q_OBJECT
  Q_DISABLE_COPY(FilteredBlockModel)

public:
  enum Filter {
    All = 0, LastHour, LastDay, LastWeek, LastMonth, LastYear, Custom
  };

  FilteredBlockModel(ICryptoNoteAdapter* _cryptoNoteAdapter, QAbstractItemModel* _blockChainModel, QObject* _parent);
  ~FilteredBlockModel();

  void setFilter(FilteredBlockModel::Filter _filter, bool _enable_period, const QDateTime &_begin, const QDateTime &_end,
                 const QString &_hash);
  void resetFilter();

protected:
  bool filterAcceptsRow(int _sourceRow, const QModelIndex &_sourceParent) const override;

private:
  ICryptoNoteAdapter* m_cryptoNoteAdapter;
  FilteredBlockModel::Filter m_filter;
  bool m_enablePeriod;
  QDateTime m_begin;
  QDateTime m_end;
  QString m_hash;
  quint32 m_beginHeight;
  quint32 m_endHeight;
};

}
