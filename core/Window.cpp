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

    glfwGetFramebufferSize(nativeWindow, &largura, &altura);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, largura, 0, altura, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, largura, altura);

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

}

void Window::takeFocus() {
    glfwMakeContextCurrent(nativeWindow);
}

bool Window::isClosing() {
    return glfwWindowShouldClose(nativeWindow);
}

void Window::update() {

    draw();

    glfwSwapBuffers(nativeWindow);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glfwPollEvents();

}

Window::~Window() {
    glfwDestroyWindow(nativeWindow);
}

Window::Window(int w, int h) {
    this->largura = w;
    this->altura = h;
    this->nativeWindow = glfwCreateWindow(w,h, "Bomberman",NULL /* Monitor */, NULL /* (?) Share */);

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
