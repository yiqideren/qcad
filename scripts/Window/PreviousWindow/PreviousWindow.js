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

include("../Window.js");

function PreviousWindow(guiAction) {
    Window.call(this, guiAction);
}

PreviousWindow.prototype = new Window();

PreviousWindow.prototype.beginEvent = function() {
    Window.prototype.beginEvent.call(this);
    var mdiArea = EAction.getMdiArea();
    // part of the workaround for QMdiArea bug
    // with events filtering through all stacked windows:
    // mdiArea.activatePreviousSubWindow();
    var windows = mdiArea.subWindowList();
    var activeWindow = mdiArea.activeSubWindow();
    var i = windows.indexOf(activeWindow);
    i--;
    i = i.mod(windows.length);
    windows[i].show();
    mdiArea.setActiveSubWindow(windows[i]);
    this.terminate();
};

