/*
Lab 11 (Chapter 13)
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.MenuBar;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuItem;
import javafx.scene.layout.BorderPane;
import javafx.scene.text.Font;

public class FontSizeSelector extends Application
{
   public static void main(String[] args)
   {
      // Launch the application.
      launch(args);
   }
   
   @Override
   public void start(Stage primaryStage)
   {
      // Constants for the scene dimensions
      final double WIDTH = 300.0, HEIGHT = 200.0;
      
      // Create the sample text.
      Label sampleText = new Label("Sample Text");
      
      // Create the menu bar.
      MenuBar menuBar = new MenuBar();
 
      // Create the File menu.
      Menu fileMenu = new Menu("File");
      MenuItem exitItem = new MenuItem("Exit");
      fileMenu.getItems().add(exitItem);
      
      // Register an event handler for the exit item.
      exitItem.setOnAction(event ->
      {
         primaryStage.close();
      });

      // Create the Font menu
      Menu fontMenu = new Menu("Font Size");
      MenuItem f6 = new MenuItem("6 points");
      MenuItem f9 = new MenuItem("9 points");
      MenuItem f12 = new MenuItem("12 points");
      MenuItem f18 = new MenuItem("18 points");
      MenuItem f24 = new MenuItem("24 points");
      fontMenu.getItems().addAll(f6, f9, f12, f18, f24);

      // Register event handlers for the fonts
      f6.setOnAction(event ->
      {
         sampleText.setStyle("-fx-font-size: 6pt");
      });

      f9.setOnAction(event ->
      {
        sampleText.setStyle("-fx-font-size: 9pt");
      });

      f12.setOnAction(event ->
      {
        sampleText.setStyle("-fx-font-size: 12pt");
      });

      f18.setOnAction(event ->
      {
        sampleText.setStyle("-fx-font-size: 18pt");
      });

      f24.setOnAction(event ->
      {
        sampleText.setStyle("-fx-font-size: 24pt");
      });

      // Add the menu to the menu bar.
      menuBar.getMenus().addAll(fileMenu, fontMenu);
         
      // Create a BorderPane with the sample text in the center.
      BorderPane borderPane = new BorderPane(sampleText);
      
      // Add the menu bar to the top region.
      borderPane.setTop(menuBar);
      
      // Create a Scene and display it.
      Scene scene = new Scene(borderPane, WIDTH, HEIGHT);
      primaryStage.setScene(scene);
      primaryStage.show();
   }
}