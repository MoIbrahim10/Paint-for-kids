#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include <vector>
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\GUI.h"

class Action; // Forward Declaration

// Main class that manages everything in the application.
class ApplicationManager
{

private:
	//Vector for drawn figures 
	vector<CFigure *> FigList;
	//Vector to save copy/cut figures 
	vector<CFigure *> Clipboard;
	//Vector to save selected figures
	vector<CFigure *> selectedfigure;
	//Pointer to GUI Class 
	GUI *pGUI;
	//Counter to the file being used in UNDO/REDO function
	int fileCounter;

public:
	ApplicationManager();
	~ApplicationManager();
		// to run the application
	void Run(); 

	// -- Action-Related Functions
	Action *CreateAction(ActionType);
	void ExecuteAction(Action *&); // Execute an action

	// -- Figures Management Functions
		// Adds a new figure to the FigList
	void AddFigure(CFigure *pFig);			
		// Search for a figure given a point inside the figure
	CFigure *GetFigure(int x, int y) const; 
		// Get a refrence to the Figure list
	vector<CFigure *> &GetFigtList();
		// Push selected figures into selectedfigure Vector
	void pushselectedfigure(CFigure *pFig);
		// Pop selected figures from selectedfigure Vector
	void popselectedfigure(CFigure *pFig);
	vector<CFigure *> &getselectedfigure();
	void ClearSelectedFigs();
		// Get the ID of Figure in Runtime (based on it's index in the figure vector)
	int GetFigureIndex(CFigure *x);
		// Clear figure Vector
	void ClearFigList();

	// Delete Selected Figures from Figures Vector
	void DeleteFigure();

	// Cut/Copy/Paste Actions
	void SetClipboard(vector<CFigure *>);
	vector<CFigure *> &GetClipboard();
	void clearClipboard();

	//For Play Mode
	string GetRandomFigure(int& Count)const;
	color GetRandomColor(int& Count)const;
	string GetRandomColorType(int& Count, color& FigColor) const;
	virtual color String2Color(string s) const;  //convert from string to color type
	virtual string Color2String(color c) const; //Convert color to string 
	void showAllFigure();

	// For all color action
	void GetColor(color&);

	// for Save/Load Actions
	void SaveScreen(ofstream&);
	void setFileCounter(int);
	int getFileCounter();

	// -- Interface Management Functions
	GUI *GetGUI() const;					// Return pointer to the interface
	void UpdateInterface() const; // Redraws all the drawing window
};

#endif