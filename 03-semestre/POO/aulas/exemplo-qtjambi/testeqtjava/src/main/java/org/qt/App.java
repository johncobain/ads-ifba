package org.qt;

import io.qt.widgets.*;
import io.qt.gui.*;
import io.qt.core.*;

public class App {
    public void onTriggered() {
    }
    public static void main(String[] args) {
        QApplication.initialize(args);

        MyMainWindow mw = new MyMainWindow();

        mw.show();

        QApplication.exec();
        QApplication.shutdown();
    }
}
