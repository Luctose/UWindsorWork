/*
    Testing java code
*/

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;

public class Testing extends Application
{
    public static void main(String [] args){
        launch(args);
    }

    @Override
    public void start(Stage primaryStage){
        primaryStage.setTilte("New title");
        primaryStage.show();
    }
}
