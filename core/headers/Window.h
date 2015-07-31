/*
 * Window.h
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include "Drawer.h"

#include <GLFW/glfw3.h>

class Window {
public:
	Window();
    Window(int w, int h);
    void setup();
    void takeFocus();
    bool isClosing();
    void update();
    ~Window();
    void draw();

    int getAltura() const;
	void setAltura(int altura);
	const Drawer& getDrawer() const;
	void setDrawer(Drawer& drawer);
	int getLargura() const;
	void setLargura(int largura);
	GLFWwindow*& getNativeWindow();
	void setNativeWindow(GLFWwindow*& nativeWindow);

protected:
   GLFWwindow* nativeWindow;
   
   Drawer drawer;
   
   int largura;
   int altura;
};

#endif /* WINDOW_H_ */
