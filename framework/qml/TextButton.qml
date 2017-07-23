/*
 *  Copyright (C) 2017 Michael Bohlender, <bohlender@kolabsys.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

import QtQuick 2.7
import QtQuick.Templates 2.0 as T
import org.kube.framework 1.0

T.Button {
    id: root

    property alias color: label.color

    width: Math.max(Units.gridUnit, contentItem.implicitWidth + leftPadding + rightPadding)
    height: contentItem.implicitHeight + topPadding + bottomPadding

    clip: true
    hoverEnabled: true
    Keys.onReturnPressed: root.clicked()

    contentItem: Label {
        id: label
        text: root.text
        font.underline: root.activeFocus || root.hovered
        elide: Text.ElideRight
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
