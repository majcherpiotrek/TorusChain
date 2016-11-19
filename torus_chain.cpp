#include "Torus.h"

GLfloat r = 0.25;
GLfloat R = 0.75;
GLint N = 20;
GLint nT = 10;
GLfloat chainR = 3.0;
/*************************************************************************************/
static GLfloat theta[] = {0.0, 0.0, 0.0}; // trzy kąty obrotu
// Funkcja rysująca osie układu współrzędnych

enum Model{
    POINTS, NET, TRIANGLES
};

Model model = POINTS;
void Axes(void)
{

    point3  x_min = {-7.0, 0.0, 0.0};
    point3  x_max = { 7.0, 0.0, 0.0};
    // początek i koniec obrazu osi x

    point3  y_min = {0.0, -7.0, 0.0};
    point3  y_max = {0.0,  7.0, 0.0};
    // początek i koniec obrazu osi y

    point3  z_min = {0.0, 0.0, -7.0};
    point3  z_max = {0.0, 0.0,  7.0};
    //  początek i koniec obrazu osi y

    glColor3f(1.0f, 0.0f, 0.0f);  // kolor rysowania osi - czerwony
    glBegin(GL_LINES); // rysowanie osi x

        glVertex3fv(x_min);
        glVertex3fv(x_max);

    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);  // kolor rysowania - zielony
    glBegin(GL_LINES);  // rysowanie osi y

        glVertex3fv(y_min);
        glVertex3fv(y_max);                           

    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);  // kolor rysowania - niebieski
    glBegin(GL_LINES); // rysowanie osi z

        glVertex3fv(z_min);
        glVertex3fv(z_max);

    glEnd();

}
bool spin = true;

void drawTorus()
{
	Torus t = *(new Torus(N, r, R));
    switch(model)
    {
        case POINTS:
        {
            for(int i = 0; i < N-1; i++)
            {
                for(int k = 0; k < N-1; k++)
                {
                    glBegin(GL_POINTS);
                        glColor3f(0.0f, 1.0f, 1.0f);
                        glVertex3f(t.getX(i,k), t.getY(i,k), t.getZ(i,k));
                    glEnd();
                }
            }
            break;
        }/*end case POINTS*/

        case NET:
        {
            for(int i = 0; i < N-1; i++)
            {
                for(int k = 0; k < N-1; k++)
                {
                    glBegin(GL_LINES);
                        if(i == 0)
                            glColor3f(0.0f, 1.0f, 0.0f);
                        else
                            glColor3f(0.0f, 0.0f, 1.0f);
                        glVertex3f(t.getX(i,k), t.getY(i,k), t.getZ(i,k));
                        glVertex3f(t.getX(i,k+1), t.getY(i,k+1), t.getZ(i,k+1));
                    glEnd();

                    glBegin(GL_LINES);
                        if(i == 0)
                            glColor3f(0.0f, 1.0f, 0.0f);
                        else
                            glColor3f(0.0f, 0.0f, 1.0f);
                        glVertex3f(t.getX(i,k), t.getY(i,k), t.getZ(i,k));
                        glVertex3f(t.getX(i+1,k), t.getY(i+1,k), t.getZ(i+1,k));
                    glEnd();

                    glBegin(GL_LINES);
                        if(i == 0)
                            glColor3f(0.0f, 1.0f, 0.0f);
                        else
                            glColor3f(0.0f, 0.0f, 1.0f);
                        glVertex3f(t.getX(i,k), t.getY(i,k), t.getZ(i,k));
                        glVertex3f(t.getX(i+1,k+1), t.getY(i+1,k+1), t.getZ(i+1,k+1));
                    glEnd();
                
                }
            }
            break;
        }/*end case NET*/

        case TRIANGLES:
        {
                    for(int i = 0; i < N-1; i++)
                    {
                        for(int k = 0; k < N-1; k++)
                        {
                            glBegin(GL_TRIANGLES);
                                glColor3f(1.0f, 0.0f, 0.0f);
                                glVertex3f(t.getX(i,k), t.getY(i,k), t.getZ(i,k));
                                glColor3f(0.0f, 1.0f, 0.0f);
                                glVertex3f(t.getX(i,k+1), t.getY(i,k+1), t.getZ(i,k+1));
                                glColor3f(0.0f, 0.0f, 1.0f);
                                glVertex3f(t.getX(i+1,k), t.getY(i+1,k), t.getZ(i+1,k));
                            glEnd();

                            glBegin(GL_TRIANGLES);
                                glColor3f(0.0f, 1.0f, 0.0f);
                                glVertex3f(t.getX(i,k+1), t.getY(i,k+1), t.getZ(i,k+1));
                                glColor3f(1.0f, 0.0f, 0.0f);
                                glVertex3f(t.getX(i+1,k+1), t.getY(i+1,k+1), t.getZ(i+1,k+1));
                                glColor3f(0.0f, 0.0f, 1.0f);
                                glVertex3f(t.getX(i+1,k), t.getY(i+1,k), t.getZ(i+1,k));
                            glEnd();
                        }
                    } 
        }/*end case TRIANGLES*/
    }
}   

void RenderScene(void)
{

     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Czyszczenie okna aktualnym kolorem czyszczącym

    glLoadIdentity();
    // Czyszczenie macierzy bieżącej

    //Axes();
    // Narysowanie osi przy pomocy funkcji zdefiniowanej wyżej

    // GLfloat R = chainR*M_PI/nT;
    // GLfloat r = R/4;
    // GLfloat N = 20;

    // std::cout << R << std::endl << r << std::endl << N << std::endl;
    // GLfloat* chain1D = new GLfloat[nT];
    // for(int i = 0; i < nT; i++)
    //     chain1D[i] = (float)i/(nT-1);

    // point3* chain3D = new point3[nT];

    //  for(int i = 0; i < nT; i++)
    // {
    //     chain3D[i][0]= chainR*cos(2*M_PI*chain1D[i]);
    //     chain3D[i][1]= chainR*sin(2*M_PI*chain1D[i]);
    //     chain3D[i][2]= 0;
    //     // std::cout << chain3D[i][0] << " " << chain3D[i][1] << " " << chain3D[i][2] << std::endl;
    // }



    /*Tu będą rysowane torusy o środkach wyliczonych wyżej*/
    // for(int i = 0; i < nT; i++)
    // {
    //     // glBegin(GL_POINTS);
    //     //     glColor3f(1.0f, 0.0f, 0.0f);
    //     //     glVertex3f(chain3D[i][0], chain3D[i][1], chain3D[i][2]);
    //     // glEnd();
    //     glTranslated(chain3D[i][0], chain3D[i][1], chain3D[i][2]);
        //drawTorus(N,r,R);
    //}

    

    glRotatef(theta[0], 1.0, 0.0, 0.0);

    glRotatef(theta[1], 0.0, 1.0, 0.0);

    glRotatef(theta[2], 0.0, 0.0, 1.0);

    glTranslated((-4)*R, 0.0f, 0.0f);

    drawTorus();

    glTranslated(8*R, 0.0f, 0.0f);

    drawTorus();
    
    glFlush();
    // Przekazanie poleceń rysujących do wykonania

 

    glutSwapBuffers();
    //

 }

 /*************************************************************************************/

// Funkcja ustalająca stan renderowania

void keys(unsigned char key, int x, int y)
{
    if(key == 'p') model = POINTS;
    if(key == 'w') model = NET;
    if(key == 's') model = TRIANGLES;
    if(key == ' ') spin = !spin;
   
    RenderScene(); // przerysowanie obrazu sceny
}

void spinEgg()
{

    if(spin)
    {
        theta[0] -= 0.5;
        if( theta[0] > 360.0 ) theta[0] -= 360.0;

        theta[1] -= 0.5;
        if( theta[1] > 360.0 ) theta[1] -= 360.0;

        theta[2] -= 0.5;
        if( theta[2] > 360.0 ) theta[2] -= 360.0;

        glutPostRedisplay(); //odświeżenie zawartości aktualnego okna
    }
    
}

void MyInit(void)
{

glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
// Kolor czyszcący (wypełnienia okna) ustawiono na czarny

}

/*************************************************************************************/

// Funkcja ma za zadanie utrzymanie stałych proporcji rysowanych
// w przypadku zmiany rozmiarów okna.
// Parametry vertical i horizontal (wysokość i szerokość okna) są
// przekazywane do funkcji za każdym razem gdy zmieni się rozmiar okna.

 

void ChangeSize(GLsizei horizontal, GLsizei vertical )
{

    GLfloat AspectRatio;
    // Deklaracja zmiennej AspectRatio  określającej proporcję
    // wymiarów okna 

    if(vertical == 0)  // Zabezpieczenie przed dzieleniem przez 0

        vertical = 1;  

    glViewport(0, 0, horizontal, vertical);
    // Ustawienie wielkościokna okna widoku (viewport)
    // W tym przypadku od (0,0) do (horizontal, vertical)  

    glMatrixMode(GL_PROJECTION);
    // Przełączenie macierzy bieżącej na macierz projekcji 

    glLoadIdentity();
    // Czyszcznie macierzy bieżącej            

    AspectRatio = (GLfloat)horizontal/(GLfloat)vertical;
    // Wyznaczenie współczynnika  proporcji okna
    // Gdy okno nie jest kwadratem wymagane jest określenie tak zwanej
    // przestrzeni ograniczającej pozwalającej zachować właściwe
    // proporcje rysowanego obiektu.
    // Do okreslenia przestrzeni ograniczjącej służy funkcja
    // glOrtho(...)            

    if(horizontal <= vertical)

        glOrtho(-7.5,7.5,-7.5/AspectRatio,7.5/AspectRatio,10.0, -10.0); 

    else

        glOrtho(-7.5*AspectRatio,7.5*AspectRatio,-7.5,7.5,10.0,-10.0);                     

    glMatrixMode(GL_MODELVIEW);
    // Przełączenie macierzy bieżącej na macierz widoku modelu                                    

    glLoadIdentity();
    // Czyszcenie macierzy bieżącej

}

/*************************************************************************************/

// Główny punkt wejścia programu. Program działa w trybie konsoli

 

int main(int argc, char** argv)
{          
	glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH);

    glutInitWindowSize(300, 300);

    glutCreateWindow("TorusChain");
                  
    glutDisplayFunc(RenderScene);
    // Określenie, że funkcja RenderScene będzie funkcją zwrotną
    // (callback function).  Bedzie ona wywoływana za każdym razem
    // gdy zajdzie potrzba przeryswania okna 

    glutReshapeFunc(ChangeSize);
    // Dla aktualnego okna ustala funkcję zwrotną odpowiedzialną
    // zazmiany rozmiaru okna      

    MyInit();
    // Funkcja MyInit() (zdefiniowana powyżej) wykonuje wszelkie
    // inicjalizacje konieczne  przed przystąpieniem do renderowania 

    glEnable(GL_DEPTH_TEST);
    // Włączenie mechanizmu usuwania powierzchni niewidocznych

    glutKeyboardFunc(keys);

    glutIdleFunc(spinEgg);

    glutMainLoop();
    // Funkcja uruchamia szkielet biblioteki GLUT
    return 0;
}