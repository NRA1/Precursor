import QtQuick
import ViewModel
import QtQuick.Controls

import ViewModel

import "Node"

Flickable {
    id: scrollView
    width: parent.width
    height: parent.height

    contentWidth: scene.width
    contentHeight: scene.height

    Rectangle {
        id: scene
        width: ViewModel.nodes.nodeBounds.width < scrollView.width ? scrollView.width : ViewModel.nodes.nodeBounds.width
        height: ViewModel.nodes.nodeBounds.height < scrollView.height ? scrollView.height : ViewModel.nodes.nodeBounds.height

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

    ScrollBar.vertical: ScrollBar { }
    ScrollBar.horizontal: ScrollBar { }
}