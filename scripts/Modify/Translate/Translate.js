/**
 * Copyright (c) 2011-2015 by Andrew Mustun. All rights reserved.
 * 
 * This file is part of the QCAD project.
 *
 * QCAD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QCAD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QCAD.
 */

include("../Transform.js");

/**
 * \class Translate
 * \brief Translates (moves or copies) selected entities. Supports multiple copies.
 * \ingroup ecma_modify
 */
function Translate(guiAction) {
    Transform.call(this, guiAction);

    this.referencePoint = undefined;
    this.targetPoint = undefined;
}

Translate.prototype = new Transform();

Translate.includeBasePath = includeBasePath;

Translate.State = {
    SettingReferencePoint : 0,
    SettingTargetPoint : 1
};

Translate.prototype.beginEvent = function() {
    Transform.prototype.beginEvent.call(this);

    if (!this.verifySelection()) {
        return;
    }

    this.setState(Translate.State.SettingReferencePoint);
};

Translate.prototype.initState = function(state) {
    this.getDocumentInterface().setClickMode(RAction.PickCoordinate);
    this.setCrosshairCursor();

    var appWin = RMainWindowQt.getMainWindow();
    switch (this.state) {
    case Translate.State.SettingReferencePoint:
        this.referencePoint = undefined;
        this.targetPoint = undefined;
        var trReferencePoint = qsTr("Reference point");
        this.setCommandPrompt(trReferencePoint);
        this.setLeftMouseTip(trReferencePoint);
        this.setRightMouseTip(EAction.trCancel);
        break;

    case Translate.State.SettingTargetPoint:
        this.targetPoint = undefined;
        var trTargetPoint = qsTr("Target point");
        this.setCommandPrompt(trTargetPoint);
        this.setLeftMouseTip(trTargetPoint);
        this.setRightMouseTip(EAction.trBack);
        break;
    }

    EAction.showSnapTools();
};

Translate.prototype.escapeEvent = function() {
    switch (this.state) {
    case Translate.State.SettingReferencePoint:
        Transform.prototype.escapeEvent.call(this);
        break;

    case Translate.State.SettingTargetPoint:
        this.setState(Translate.State.SettingReferencePoint);
        break;
    }
};

Translate.prototype.pickCoordinate = function(event, preview) {
    var di = this.getDocumentInterface();

    switch (this.state) {
    case Translate.State.SettingReferencePoint:
        if (!preview) {
            this.referencePoint = event.getModelPosition();
            di.setRelativeZero(this.referencePoint);
            this.setState(Translate.State.SettingTargetPoint);
        }
        break;

    case Translate.State.SettingTargetPoint:
        this.targetPoint = event.getModelPosition();

        if (preview) {
            di.previewOperation(this.getOperation(true));
        }
        else {
            this.setState(-1);
            if (!this.showDialog()) {
                // dialog canceled:
                this.terminate();
                return;
            }


            di.applyOperation(this.getOperation(false));
            di.setRelativeZero(this.targetPoint);
            this.terminate();
        }
        break;
    }
};

Translate.prototype.getOperation = function(preview, selectResult) {
    if (isNull(this.copies)) {
        return undefined;
    }

    if (isNull(selectResult)) {
        selectResult = true;
    }

    var di = this.getDocumentInterface();

    var op = new RModifyObjectsOperation();
    var offset = this.targetPoint.operator_subtract(this.referencePoint)
    var transformation = new RTranslation(offset);
    op.transformSelection(transformation, di, this.copies, preview, selectResult, this.useCurrentAttributes);

    return op;
};

/**
 * Shows the translation dialog.
 *
 * \return True if the dialog was accepted, false if it was canceled.
 */
Translate.prototype.showDialog = function() {
    var dialog = WidgetFactory.createDialog(Translate.includeBasePath, "TranslateDialog.ui");
    WidgetFactory.restoreState(dialog);
    if (!dialog.exec()) {
        dialog.destroy();
        return false;
    }

    var widgets = getWidgets(dialog);
    if (widgets["DeleteOriginal"].checked===true) {
        this.copies = 0;
    }
    else if (widgets["KeepOriginal"].checked===true) {
        this.copies = 1;
    }
    else {
        this.copies = widgets["NumberOfCopies"].getValue();
    }

    this.useCurrentAttributes = (widgets["UseCurrentAttributes"].checked===true);

    WidgetFactory.saveState(dialog);

    dialog.destroy();
    return true;
};

/**
 * Callback function for Transform.getOperation.
 */
//Translate.prototype.transform = function(entity, k, op, preview, forceNew) {
//    var delta = this.targetPoint.operator_subtract(this.referencePoint);
//    entity.move(delta.operator_multiply(k));
//    op.addObject(entity, this.useCurrentAttributes, forceNew);
//};

