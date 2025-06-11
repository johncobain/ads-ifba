package org.qt;

import io.qt.widgets.*;
import io.qt.gui.*;
import io.qt.core.*;

public class MyMainWindow extends QMainWindow
{
    public MyMainWindow() {
        QMenuBar mb = new QMenuBar();
        QMenu fileMenu = new QMenu("&File");
        QAction action = fileMenu.addAction(QIcon.fromTheme(QIcon.ThemeIcon.ApplicationExit), "E&xit");
        mb.addMenu(fileMenu);

        setMenuBar(mb);
        QToolBar toolbar = new QToolBar();
        toolbar.addAction(action);
        addToolBar(toolbar);

        connect(action, "triggered(boolean)", this, "onTriggered(boolean)");
    }
    public void onTriggered(boolean checked) {
        close();
    }
}
