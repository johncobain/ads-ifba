package org.openjfx;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.scene.layout.Region;
import javafx.geometry.Insets;
import javafx.geometry.Pos;

/**
 * JavaFX App
 */
public class App extends Application {

    @Override
    public void start(Stage stage) {
        var javaVersion = SystemInfo.javaVersion();
        var javafxVersion = SystemInfo.javafxVersion();

        var scene = new Scene(createContents(), 640, 480);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }

    private Region createContents() {
        TextField inputTextField = new TextField("");
        HBox inputRow = new HBox(new Label("Name:"), inputTextField);
        inputRow.setSpacing(6);
        inputRow.setAlignment(Pos.CENTER);
        Label outputLabel = new Label("");
        Button actionButton = new Button("Hello");
        actionButton.setOnAction(evt -> outputLabel.setText("Hello " + inputTextField.getText()));
        VBox results = new VBox(20, inputRow, outputLabel, actionButton);
        results.setAlignment(Pos.CENTER);
        return results;
    }
}
