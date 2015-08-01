/*
 * Window.cpp
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#include <GL/gl.h>
#include <iostream>
#include <string>

using namespace std;

#include "headers/Window.h"

void Window::setup() {
    takeFocus();

    glfwGetFramebufferSize(nativeWindow, &sizePxX, &sizePxY);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, sizePxX, 0, sizePxY, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, sizePxX, sizePxY);

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

}

void Window::takeFocus() {
    glfwMakeContextCurrent(nativeWindow);
}

bool Window::isClosing() {
    return glfwWindowShouldClose(nativeWindow);
}

void Window::update() {

    glfwSwapBuffers(nativeWindow);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glfwPollEvents();

}

Window::~Window() {
    glfwDestroyWindow(nativeWindow);
}

Window::Window(Map* map) {
	glfwInit();
	this->map = map;
	sizePxX = map->getSizePxX();
	sizePxY = map->getSizePxY();
    this->nativeWindow = glfwCreateWindow(map->getSizePxX(),map->getSizePxY(), "Bomberman",NULL /* Monitor */, NULL /* (?) Share */);

    if (this->nativeWindow == NULL)
    {
        cerr << "Janela não inicializada" << endl;
        //exit(-1);
    }

}

void Window::draw(){

}

GLFWwindow*& Window::getNativeWindow() {
	return nativeWindow;
}

Map* Window::getMap() {
	return map;
}

void Window::setMap(Map* map) {
	this->map = map;
}
