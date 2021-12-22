/*
Lab 11 (Chapter 12)
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

// Import statements
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import javafx.geometry.Pos;
import javafx.geometry.Insets;

/**
 * GUI that calculates a 20% tip based on the bill
 */
public class TipCalculator extends Application{
    /**
     * Main entry to program
     * @param args Arguments from execution
     */
    public static void main(String[] args){
        launch(args);
    }

    /**
     * Auto sets stage; creates layout and handles events
     */
    @Override
    public void start(Stage stg){
        // Create controls for the stage
        Label title = new Label("Restaurant Charge:");
        Label subTitle = new Label("Amount to Tip:");
        Label amount = new Label();
        TextField charge = new TextField();
        Button calculate = new Button("Calculate Tip");

        // Register Event hander, lambda expression
        calculate.setOnAction(e -> {
            amount.setText(String.format("$%.2f", Double.parseDouble(charge.getText()) * 0.20));
        });
        // Create VBox to align
        VBox align = new VBox(10, title, charge, calculate, subTitle, amount); // Add controls to VBox
        align.setAlignment(Pos.CENTER); // Center VBox
        align.setPadding(new Insets(10)); // Set padding
        Scene scene = new Scene(align); // Set a scene with the Vbox as the root node
        stg.setScene(scene); // Set the stages scene to the one we created
        stg.show(); // Show the stage
    }
}
