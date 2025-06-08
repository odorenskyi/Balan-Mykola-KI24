#ifndef MODULESBALAN_H
#define MODULESBALAN_H

class ClassLab12_Cube {
private:
    float edge; 

public:
    ClassLab12_Cube() : edge(0) {}

    void setEdge(float value) { edge = value; }
    float getSurfaceArea() {
        return 6 * pow(edge, 2);
    }
};

#endif