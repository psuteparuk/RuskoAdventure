#define NOMINMAX
#define _USE_MATH_DEFINES

#include "Box.h"


Box::Box() : Model("models/WoodCrate_OBJ/WoodCrate_OBJ.obj") {
	
}


Box::Box(float scale) : Model("models/WoodCrate_OBJ/WoodCrate_OBJ.obj", scale) {

}

Box::~Box() {
	
}

void Box::render() {
	Model::render();
}

void Box::render(int frame) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix ();
    glLoadIdentity();
    
    frame = frame % cr->totalPoints;
    STPoint3 fu = cr->pointAt(frame);
    glTranslatef(0, fu.y, 0);  //translates to new position
    
    Model::render();

    glPopMatrix ();
}

void Box::setMove(float height){
    cr = new CatmullRom();
    cr->addControlPoint(0, 0, 0);
    cr->addControlPoint(0, height/2, 0);
    cr->addControlPoint(0, height-(height/3), 0);
    cr->addControlPoint(0, height, 0);
    cr->addControlPoint(0, height-(height/3), 0);
    cr->addControlPoint(0, height/2, 0);
    cr->addControlPoint(0, 0, 0);
    cr->done();
}