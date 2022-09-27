# Plotted 2D Environment

## Overview

Plotted 2D Environment is a graphical project focused on creating and animating 2D polygons within a defined environment. This project demonstrates the use of graphical libraries and techniques to visualize and manipulate polygonal shapes.

<p align= "center">
    <img src="https://github.com/KPlanisphere/binary-tree-operations/assets/60454942/adfca7bb-671e-4fb0-b4aa-86997989bfe8" style="width: 60%; height: auto;">
</p>

## Files and Structure

The repository contains the following files and directories:

- `PoligonoAnimadoModelado.cbp`: The project file for Code::Blocks IDE.
- `PoligonoAnimadoModelado.depend`: Dependency file for the project.
- `PoligonoAnimadoModelado.layout`: Layout configuration file for the project.
- `Report_Entorno2D.pdf`: A report detailing the project, its design, and implementation.
- `main.cpp`: The main source code file for the project.
- `bin/`: Directory for binary files.
- `include/`: Directory for header files.
- `obj/`: Directory for object files.
- `src/`: Directory for additional source files.

## Main Source File: `main.cpp`

The main logic of the project is implemented in `main.cpp`. Below is a brief overview of its content:

```cpp
// Initialization of graphical libraries
#include <GL/glut.h>

float angle = 0, rad = 0, red = 0;
int first = 1;
int band[50];
int supercont = 0;
ControlV CV[20];
ControlV CVBG[20];

// Initialization function
void init(void) {
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -240, 240);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Function to clear the screen
void clearScreen() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    Sleep(30);
}

// Function to draw the main graphical content
void drawGraphicalContent() {
    glClear(GL_COLOR_BUFFER_BIT);
    Stage show;
    show.Theater();
    supercont++;
    glFlush();
    Sleep(30);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(150, 100);
    glutInitWindowSize(1000, 480);
    glutCreateWindow("Plotted 2D Environment");
    init();
    BanderaCero(50);
    glutDisplayFunc(drawGraphicalContent);
    glutIdleFunc(drawGraphicalContent);
    glutMainLoop();
    return 0;
}
```

## Report [IMPORTANT]

The `Report_Entorno2D.pdf` file provides a comprehensive overview of the project, including:

-   Project objectives
-   Design and implementation details
-   Results and findings
-   Future work and improvements

## How to Build and Run

### Prerequisites

-   Code::Blocks IDE
-   OpenGL and GLUT libraries

### Steps

1.  Clone the repository:
    
	```bash
	git clone https://github.com/KPlanisphere/Plotted-2D-Environment.git
	```
    
2.  Open the `PoligonoAnimadoModelado.cbp` project file in Code::Blocks.
3.  Build and run the project within the IDE.