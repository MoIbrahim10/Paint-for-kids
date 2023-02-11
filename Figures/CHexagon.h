#include "CFigure.h"

class CHexagon : public CFigure
{
    int SideLength;
    int Height;
    Point TopLeft;
   
public:
    CHexagon();
    CHexagon(Point, int, int, GfxInfo FigureGfxInfo);

    void DrawMe(GUI *) const;

    bool isInside(int x, int y);

    float CHexagon::AreaTriangle(float, float, float, float, float, float);
    int resize(float);

    virtual CFigure *clone();
    CFigure *paste(int transX, int transY);
    Point highestPoint();

    void Save(ofstream& OutFile);
    void Load(ifstream& InFile);
    void printInfo(GUI *pGUI, int);
    string GetFigName();
};
