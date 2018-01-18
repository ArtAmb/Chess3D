#include "Engine3D.h"
#include "Point3D.h"
#include <vector>
Engine3D* Engine3DLoader::engine = NULL;

Engine3D::Engine3D(int argc, char**argv)
{
	init(argc, argv);
}

Engine3D::~Engine3D()
{

}

void Engine3D::createWindow() {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);

	glutCreateWindow("Chess 3D");
	//initRendering();
}

void Engine3D::init(int argc, char**argv) {
	glutInit(&argc, argv);
	createWindow();
	initRendering();
}

void Engine3D::drawLoadedModels() {

}

void Engine3D::unload() {

}
std::vector<int> iMaterialIndices;

void Engine3D::initRendering() {
	glEnable(GL_DEPTH_TEST);
	glutIgnoreKeyRepeat(1);
	//loader = new AssimpLoader();
	//loader->LoadModelFromFile("E:/MVS2015Workspace/GraphicEngine3D/woodenChess3DModels/Chess/chess.obj");

}

void Engine3D::clean(Colors::RGB color) {
	glClearColor(color.getR(), color.getG(), color.getB(), color.getA());
}

void Engine3D::setKeyboard(void(*keyboard)(unsigned char, int, int)) {
	glutKeyboardFunc(keyboard);
}

void Engine3D::setSpecialKeyboard(void(*keyboard)(int, int, int)) {
	glutSpecialFunc(keyboard);
}

void Engine3D::setDisplay(void(*dispFunc)(void)) {
	glutDisplayFunc(dispFunc);
}
void Engine3D::setReshape(void(*reshape)(int, int)) {
	glutReshapeFunc(reshape);
}

void Engine3D::setTimer(int ms, void(*update)(int), int value) {
	glutTimerFunc(ms, update, value);
}
void Engine3D::startMainLoop() {
	glutMainLoop();
}
Engine3D* Engine3D::glVertex3p(Point3D p) {
	glVertex3f(p.getX(), p.getY(), p.getZ());
	return this;
}
Engine3D* Engine3D::glColor3c(Colors::RGB c) {
	glColor3f(c.getR(), c.getG(), c.getB());
	return this;
}
void Engine3D::setSpecialUpKeyboard(void(*keyboard)(int, int, int)) {
	glutSpecialUpFunc(keyboard);
}
void Engine3D::setKeyboardUp(void(*keyboard)(unsigned char , int, int)) {
	glutKeyboardUpFunc(keyboard);
}
void Engine3D::mouseButtonsFunc(void(*mouseButton)(int, int, int, int)) {
	glutMouseFunc(mouseButton);
}
void Engine3D::mouseMotionFunc(void(*moveMotion)(int, int)) {
	glutMotionFunc(moveMotion);
}



void Engine3D::displayText(float x, float y, Colors::RGB color, std::string string) {
	glColor3f(color.getR(), color.getG(), color.getB());
	glRasterPos2f(x, y);
	for (unsigned int i = 0; i < string.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string[i]);
	}
}
