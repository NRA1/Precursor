import QtQuick
import ViewModel

import "Node"

Item {
    Repeater {
        id: repeater

        model: ViewModel.nodes

        Node { }
    }

    Rectangle {
        id: addMenu

        property var model: ViewModel.addMenu

        color: "#442345"
        height: 500
        visible: model.visible
        width: 300
        x: model.posX
        y: model.posY

        onActiveFocusChanged: {
            if (!activeFocus) {
                ViewModel.addMenu.focusLost();
            }
        }
    }

    TapHandler {
        target: null
        grabPermissions: PointerHandler.CanTakeOverFromHandlersOfDifferentType | PointerHandler.ApprovesTakeOverByHandlersOfDifferentType

        onTapped: (point, button) => ViewModel.sceneTapped(point.position)
    }
}