# Paint-for-kids
An interactive painting experience for kids - Paint for Kids is designed to spark imagination and creativity.


## Inroduction
Paint for Kids is a fun and easy-to-use digital painting tool designed specifically for kids. With a simple and intuitive interface, kids can unleash their creativity and let their imagination run wild. This project is built using C++ and object-oriented programming. The application is integrated with an open-source graphics library for easy handling of GUI (e.g. drawing figures, reading mouse clicks, etc.).


## Usage Requirements
- Your system must have a C++ compiler installed.
- The application uses an open-source graphics library that you will use to easily handle GUI, so make sure that the required libraries are installed on your system.

## Installation
1. Clone the repository to your local machine using the following command:
```shell
$ git clone https://github.com/MoIbrahim10/Paint-for-Kids.git
```
2. Navigate to the project directory:
```shell
$ cd Paint-for-Kids
```

3. Compile the project using the following command:
```shell
$ g++ main.cpp -o Paint-for-Kids
```
4.Run the application:
```shell
$ ./Paint-for-Kids
```
5. Enjoy playing with the colorful and educational game for kids!

# Features

## Draw Mode: 
The Draw Mode supports the following features: 
1. Add Figure: 
   - Add a new square
   - Add a new ellipse
   - Add a new hexagon
2. Change Current Colors:
   - Change the current drawing color
   - Change the current filling color
   - Change the window background color
3. Select/Unselect Figures:
   - Select a figure by clicking inside the figure or on its border
   - Highlight the selected figure
   - Print information about the selected figure on the status bar (ID, start/end points, center, radius, width, height, area)
   - Unselect a figure by re-clicking on it
4. Change Figures Colors:
   - Change the drawing or filling colors for the selected figure
5. Delete Figures: 
   - Delete the selected figures
6. Resize  Figures: 
   - Resize the selected figures by a factor of 1/4, 1/2, 2, or 4
7. Send to back/Bring to Front:
   - Send the selected figure to the back or bring it to the front
8. Save Graph: 
   - Save the information of the drawn graph to a file
   - Ask the user for the filename to create and save the graph in (overwrite if the file already exists)
9. Load Graph: 
   - Load a saved graph from a file and re-draw it
   - Ask the user for the filename to load from
   - Prompt the user to save the current graph if there is already a graph drawn on the drawing area
10. Switch to Play Mode: 
    - Load the tool bar and status bar of the play mode
11. Undo and Redo Action: 
    - Undo and redo all draw mode actions except save and load, up to 100 actions
12. Exit: 
    - Exit from the application after confirmation
    - Prompt the user to save the graph before exiting if the drawn graph is not saved or changed after the last save

## Play Mode: 
The Play Mode supports the following features:
1. Pick & Hide:
   - Pick a specific figure
   - Hide the picked figure
   - Count the number of valid and invalid picks done by the user
   - Display a grade when the user picks all similar figures
   - Pick figures based on:
     - Figure type (e.g. pick all ellipses)
     - Figure fill color (e.g. pick all red figures, all non-filled figures)
     - Figure type and fill color (e.g. pick all blue hexagons)
   - Restart the game or start another game at any time
2. Switch to Draw Mode: 
   - Switch back to the Draw Mode at any time
   - Restore the original graph
   - Discard all changes made in the Play Mode

## Sneak peek
![Demo Gif](https://media.giphy.com/media/0WQP0zZs2lizNFNJIc/giphy.gif)


## Contributing

We welcome contributions to Paint for Kids. If you have any suggestions or bug reports, please open an issue or submit a pull request.
