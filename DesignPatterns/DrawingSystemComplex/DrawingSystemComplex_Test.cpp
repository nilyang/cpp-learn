#include<iostream>

#include"DrawingSystemComplex.h"

#include"Circle.h"
#include"Line.h"
#include"Rec.h"

//we can use factory method to solve this problem
void Test_Drawing()
{
    //drawing circle
    DrawingSystem* drawCircle = new DrawingSystem(new CircleFactory());
    drawCircle->DoDrawing();

    //drawing line
    DrawingSystem* drawLine = new DrawingSystem(new LineFactory());
    drawLine->DoDrawing();

    //drawing rec
    DrawingSystem* drawRec = new DrawingSystem(new RecFactory());
    drawRec->DoDrawing();

    //delete pointers
    delete drawCircle;
    delete drawLine;
    delete drawRec;
}
int main()
{
    
    Test_Drawing();

    getchar();
    return 0;
}