#include "Engine3D.h"
Engine3D* Engine3DLoader::engine = nullptr;

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
	initRendering();
}

void Engine3D::init(int argc, char**argv) {
	glutInit(&argc, argv);
	createWindow();
	initRendering();
}

void Engine3D::unload() {

}

void Engine3D::initRendering() {
	glEnable(GL_DEPTH_TEST);
	glutIgnoreKeyRepeat(1);
	//glClearColor(0, 0, 0, 0);
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
void Engine3D::setSpecialUpKeyboard(void(*keyboard)(int, int, int)) {
	glutSpecialUpFunc(keyboard);
}
void Engine3D::setMouseButtons(void(*mouseButton)(int, int, int, int)) {
	glutMouseFunc(mouseButton);
}
void Engine3D::setMouseMotion(void(*moveMotion)(int, int)) {
	glutMotionFunc(moveMotion);
}