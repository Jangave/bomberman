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
#include "Map.h"

class Window {
public:
	Window();
    Window(Map* map);
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
	Map* getMap();
	void setMap(Map* map);

protected:
   GLFWwindow* nativeWindow;
   
   Drawer drawer;

   Map* map;

   int sizePxX, sizePxY;
};

#endif /* WINDOW_H_ */
