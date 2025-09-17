// Processing code to receive identifiers from Arduino and display in a table

import processing.serial.*;
Table dataTable;      // Table to store identifiers
Serial myPort;        // Declare myPort outside setup()

String[] Data_Nom = {"Mirza1","Picot1","Mirza2","Picot2","Mirza3","Picot3",
                     "Mirza4","Picot4","Mirza5","Picot5","Mirza6","Picot6",
                     "Mirza7","Picot7","Mirza8","Picot8","Mirza9","Picot9",
                     "Mirza10","Picot10"}; 
                     
String[] Data_Prenom = {"Vlad1","Baptiste1","Vlad2","Baptiste2","Vlad3","Baptiste3",
                        "Vlad4","Baptiste4","Vlad5","Baptiste5","Vlad6","Baptiste6",
                        "Vlad7","Baptiste7","Vlad8","Baptiste8","Vlad9","Baptiste9",
                        "Vlad10","Baptiste10"};
                    
String[] Data_Presence = {"Absent","Absent","Absent","Absent","Absent","Absent",
                          "Absent","Absent","Absent","Absent","Absent","Absent",
                          "Absent","Absent","Absent","Absent","Absent","Absent",
                          "Absent","Absent"};
                   
String[] Data_Identifiant = {"f3db41fa","73e7c212","________","________","________","________",
                             "________","________","________","________","________","________",
                             "________","________","________","________","________","________",
                             "________","________"};
int Correct_ID = 0;
String receivedValue = " ";
String ID_Write = " ";
String Name_Write = " ";
int Index_Write = 0;


void setup() 
{
  size(1000, 500);
  background(255);
  
  // List all the available serial ports in the console
  printArray(Serial.list());
  
  // Replace "COM3" with the correct port name based on your setup
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  
  // Création de la table avec 20 lignes et 2 colonnes
  dataTable = new Table();
  for (int i = 0; i < 20; i++) 
  {
    TableRow newRow = dataTable.addRow();
    // Ajout de données fictives pour chaque colonne (remplacez-les par vos propres données)
    newRow.setString(0, "ING4 App");
    newRow.setString(1, Data_Nom[i]);
    newRow.setString(2, Data_Prenom[i]);
    newRow.setString(3, Data_Identifiant[i]);
    newRow.setString(4, Data_Presence[i]);
    newRow.setString(5, "5");
  }
}

void draw() 
{
  while (myPort.available() > 0) 
  {
    String data = myPort.readStringUntil('\n');
    if ((data != null) && (data != "") ) 
    {
      data = data.trim();  // Supprimez les espaces inutiles
      receivedValue = data;  // Convertir la chaîne en entier
      println("ID : " + "["+receivedValue+"]");
      
      Correct_ID = 0;
      Index_Write = 0;
      
      for (int i = 0; i < 20; i++) 
      {
        if ( receivedValue.equals(Data_Identifiant[i]) && Data_Presence[i].equals("Absent"))
        {
            // Modification de la valeur dans la table
            println("Eleve : " + Data_Nom[i] + " " + Data_Prenom[i] + " Passe de " + Data_Presence[i] + " à Présent");
            modifyValueInTable(dataTable, i, 4, "Présent");
            Data_Presence[i] = "Présent";
            Correct_ID ++;
            Index_Write = i;
            ID_Write = "";
        }
      }
      
      if(Correct_ID > 0)
      {
        ID_Write = Data_Nom[Index_Write];
        println("Data_Sent : " + ID_Write);
        myPort.write(ID_Write + '\n');
        delay(1000);
        ID_Write = Data_Identifiant[Index_Write];
        println("Data_Sent : " + ID_Write);
        myPort.write(ID_Write + '\n');
      }
      else
      {
        ID_Write = "0";
        println("Data_Sent : " + ID_Write);
        myPort.write(ID_Write + '\n');
        ID_Write = "0";
        println("Data_Sent : " + ID_Write);
        myPort.write(ID_Write + '\n');
      }
    }
  }
  background(255);
  displayTable();
}

void displayTable() {
  int tableX = 50;
  int tableY = 50;
  int colWidth = 120;
  int rowHeight = 20;

  // Affichage des noms de colonnes
  fill(0);
  textAlign(CENTER, CENTER);
  text("Classe", tableX + colWidth * 0.5, tableY);
  text("Nom", tableX + colWidth * 1.5, tableY);
  text("Prénom", tableX + colWidth * 2.5, tableY);
  text("Identifiant", tableX + colWidth * 3.5, tableY);
  text("Présence", tableX + colWidth * 4.5, tableY);
  text("Assiduité", tableX + colWidth * 5.5, tableY);
  
  // Affichage des données de la table
  for (int i = 0; i < dataTable.getRowCount(); i++) 
  {
    TableRow row = dataTable.getRow(i);
    text(row.getString(0), tableX + colWidth * 0.5, tableY + (i + 1) * rowHeight);
    text(row.getString(1), tableX + colWidth * 1.5, tableY + (i + 1) * rowHeight);
    text(row.getString(2), tableX + colWidth * 2.5, tableY + (i + 1) * rowHeight);
    text(row.getString(3), tableX + colWidth * 3.5, tableY + (i + 1) * rowHeight);
    text(row.getString(4), tableX + colWidth * 4.5, tableY + (i + 1) * rowHeight);
    text(row.getString(5), tableX + colWidth * 5.5, tableY + (i + 1) * rowHeight);
  }
}

void modifyValueInTable(Table table, int rowIndex, int colIndex, String newValue) 
{
  if (rowIndex < table.getRowCount() && colIndex < table.getColumnCount()) 
  {
    TableRow rowToModify = table.getRow(rowIndex);
    rowToModify.setString(colIndex, newValue);
    //println("Valeur modifiée à la ligne " + rowIndex + ", colonne " + colIndex + ": " + newValue);
  } 
  else 
  {
    println("Indice de ligne ou de colonne invalide.");
  }
}
