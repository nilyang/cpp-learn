
#include"Circle.h"
#include"Line.h"
#include"Rec.h"
#include"ComplexShape.h"

//we can use Composite Pattern to solve this problem
void Test_Drawing()
{
    //create Shapes
    ComplexShape *complexShape = new ComplexShape("complexRoot");
    Circle *circle = new Circle("Circle");
    Rec *rect = new Rec("Rectangle");
    Line *line = new Line("Line");
    ComplexShape *complexShape2 = new ComplexShape("complexChild");
    Line *line2 = new Line("Line2");

    //1. Composing Shapes in one Big "ComplexShape"
    //Big Complex Shape by three Leaf Shape
    complexShape->AddShape(circle);
    complexShape->AddShape(rect);
    complexShape->AddShape(line);
    
    //2. Sub Complex Shape composted by One Leaf Shape
    complexShape2->AddShape(line2);
    //Big Complex Shape include one Complex Shape.
    complexShape->AddShape(complexShape2);

    //3. You can remove one shape from ComplexShape
    complexShape->RemoveShape(rect);


    complexShape->Drawing();

    if (complexShape) {
        delete complexShape;
    }
}

int main()
{
    
    Test_Drawing();

    getchar();
    return 0;
}