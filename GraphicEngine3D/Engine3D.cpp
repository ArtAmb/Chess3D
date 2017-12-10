#include "Engine3D.h"
Engine3D* Engine3DLoader::engine = nullptr;

Engine3D::Engine3D()
{
	init();
}

Engine3D::~Engine3D()
{

}

void Engine3D::createWindow() {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);

	glutCreateWindow("Chess 3D");
	initRendering();
}

void Engine3D::init() {
	createWindow();
	initRendering();
}

void Engine3D::unload() {

}

void Engine3D::initRendering() {
	glClearColor(0, 0, 0, 0);
}

void Engine3D::clean(Colors::RGB color){
	glClearColor(color.getR(), color.getG(), color.getB(), color.getA());
}

void Engine3D::setKeyboard(void(*keyboard)(unsigned char, int,int)) {
	glutKeyboardFunc(keyboard);
}
void Engine3D::setDisplay(void(*dispFunc)(void)) {
	glutDisplayFunc(dispFunc);
}
void Engine3D::setReshape(void(*reshape)(int,int)) {
	glutReshapeFunc(reshape);
}

void Engine3D::startMainLoop() {
	glutMainLoop();
}

