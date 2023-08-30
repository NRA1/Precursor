import QtQuick
import QtQuick.Controls
import Qt5Compat.GraphicalEffects
import QtQuick.Shapes

import Precursor.NodeShape
import ViewModel

Item {
    required property int index
    required property var model

    id: nodeWrapper

    NodeShape {

        property alias index: nodeWrapper.index
        property alias model: nodeWrapper.model


        id: node

        x: model.posX
        y: model.posY

        shape: model.shape

        Label {
            id: label
            visible: !textInput.activeFocus

            text: parent.model.display
            color: "#ffffff"
            anchors.centerIn: parent

            TapHandler {
                gesturePolicy: TapHandler.WithinBounds

                onTapped: {
                    textInput.focus = true;
                    textInput.selectAll()
                }
            }
        }

        TextInput {
            id: textInput

            visible: activeFocus
            color: "#ffffff"

            anchors.centerIn: parent
            text: parent.model.display

            onActiveFocusChanged: if (activeFocus) tapHandler.enabled = true;
            onTextEdited: parent.model.display = text;
        }

        Keys.onDeletePressed: event => {
            ViewModel.nodes.deletePressed(parent.index);
        }

        Keys.onTabPressed: event => {
            ViewModel.nodes.tabPressed(parent.index)
            addMenu.focus = true
        }

        TapHandler {
            id: tapHandler
            gesturePolicy: TapHandler.WithinBounds
            grabPermissions: PointerHandler.CanTakeOverFromHandlersOfDifferentType | PointerHandler.ApprovesTakeOverByHandlersOfDifferentType


            onTapped: x => {
                parent.focus = true;
            }
        }

        DragHandler {
            target: null

            onGrabChanged: (transition, point) => {
                if (transition === PointerDevice.GrabExclusive)
                    parent.focus = true;
            }
            xAxis.onActiveValueChanged: delta => model.posX += delta
            yAxis.onActiveValueChanged: delta => model.posY += delta
        }

        Component.onCompleted: {
            node.focus = true;
        }
    }

    DropShadow {
        visible: node.activeFocus || textInput.activeFocus
        anchors.fill: node
        color: "#000000"
        horizontalOffset: 3
        radius: 8.0
        source: node
        verticalOffset: 3
    }
}