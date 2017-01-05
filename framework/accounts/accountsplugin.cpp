/*
  Copyright (C) 2017 Michael Bohlender, <michael.bohlender@kdemail.net>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#include "accountsplugin.h"

#include "accountsmodel.h"
#include "accountfactory.h"
#include "maildircontroller.h"

#include <QtQml>

void AccountsPlugin::registerTypes (const char *uri)
{
    Q_ASSERT(uri == QLatin1String("org.kube.framework.accounts"));
    qmlRegisterType<AccountFactory>(uri, 1, 0, "AccountFactory");
    qmlRegisterType<AccountsModel>(uri, 1, 0, "AccountsModel");
    qmlRegisterType<MaildirController>(uri, 1, 0, "MaildirController");
}
