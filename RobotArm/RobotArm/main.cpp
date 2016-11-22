#ifdef _DEBUG
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")
#else
#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-network.lib")
#endif
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")

#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"
#include <iostream>



////////////////////////////////////////////////////////////
///Entrypoint of application
////////////////////////////////////////////////////////////

int main()
{
    // Create the main window
    
    int width =1600;
    int height = 800;
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML First Program");
    //window.setFramerateLimit(60);
    
    
    
    const int size=5;
    const int bluesize=5;
    const int armSize=7;
    
    sf::VertexArray lines(sf::LinesStrip, size);
    
    //end vertex is used as start vertex of the next one
    sf::Vector2f greenRect[size];
    greenRect[0]=sf::Vector2f(0,0);//start at origin
    greenRect[1]=sf::Vector2f(200,0);//go out 200
    greenRect[2]=sf::Vector2f(200,-50);//drop 50
    
    greenRect[3]=sf::Vector2f(0,-50);//go in to axis
    greenRect[4]=greenRect[0];
    
    
    
    sf::VertexArray blueLines(sf::LinesStrip, bluesize);
    
    //end vertex is used as start vertex of the next one
    sf::Vector2f blueRect[size];
    blueRect[0]=sf::Vector2f(0,0);//start at origin
    blueRect[1]=sf::Vector2f(200,0);//go out 200
    blueRect[2]=sf::Vector2f(200,-50);//drop 50
    blueRect[3]=sf::Vector2f(0,-50);//go in to axis
    blueRect[4]=blueRect[0];
    
    
    
    sf::VertexArray rightLines(sf::LinesStrip, armSize);
    
     sf::Vector2f RightArm[armSize];
     
     RightArm[0]=sf::Vector2f(0,0);
     
     RightArm[1]=sf::Vector2f(0,150);
     RightArm[2]=sf::Vector2f(150,150);//was 150,150
     RightArm[3]=sf::Vector2f(100,100);//was 150,100
     RightArm[4]=sf::Vector2f(50,100);//was 50,100
     RightArm[5]=sf::Vector2f(50,0);//was 50,0
     
     RightArm[6]=blueRect[0];
    
    
    sf::VertexArray leftLines(sf::LinesStrip, armSize);
    
    sf::Vector2f leftArm[armSize];
    
    leftArm[0]=sf::Vector2f(0,0);
    
    leftArm[1]=sf::Vector2f(0,-150);
    leftArm[2]=sf::Vector2f(150,-150);//was 150,150
    leftArm[3]=sf::Vector2f(100,-100);//was 150,100
    leftArm[4]=sf::Vector2f(50,-100);//was 50,100
    leftArm[5]=sf::Vector2f(50,0);//was 50,0
    
    leftArm[6]=blueRect[0];
    
    
    
    sf::Vector2f pos(0,0);
    
    sf::Vector2f vel(1.0,0.5);
    
    float rotation=0.0;
    float rotationVel=0.0;
    
    float bluerotation =0.0;
     float bluerotationVel=0.0;
    
    float leftrotation =0.0;
    float leftrotationVel =0.0;
    
    float rightrotation =0.0;
    float rightrotationVel =0.0;

    
    // Start game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            // Close window : exit
            if (Event.type == sf::Event::Closed)
                window.close();
            
            // Escape key : exit
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
                window.close();
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::A))
            {
                if (rotation !=-90)
                {
                    rotation = rotation-1;
                }
                
            }
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::S))
            {
                
                if (rotation !=90 )
                {
                    rotation = rotation+1;
                }
            }
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Z))
            {
                if(bluerotation != -90)
                {
                        bluerotation = bluerotation-1;
                }
            }
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::X))
            {
                
                if(bluerotation != 90)
                {
                    bluerotation = bluerotation+1;
                }
            }
            //q to close w to open
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Q))
            {
                if(rightrotation != -45)
                {
                    rightrotation = rightrotation-1;
                }
            }
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::W))
            {
                
                if(rightrotation != 10 )
                {
                    rightrotation = rightrotation+1;
                    
                }
            }
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Q))
            {
                if(leftrotation != 45)
                {
                    leftrotation = leftrotation+1;
                }
            }
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::W))
            {
                
                if(leftrotation != -10 )
                {
                    leftrotation = leftrotation-1;
                }
               
            }

            
        }
        float temp = bluerotation;
        
        
        //GREEN RECTANGLE
        sf::Transform T;//create a transformation
        T.translate(width/2, height/2);//translate it to the center of the screen
        
        rotation+=rotationVel;//get a rotation velocity
        sf::Transform R;//Create a transformation R
        R.rotate(rotation);
        
        sf::Transform M=T*R;//Create a transformation that is the center position transformation by the rotation transformation
        
        
        
        //BlUE RECTANGLE
        sf::Transform blueTransformation;//create a transformation
        blueTransformation.translate(200,0);//translate it to the center of the screen
        
        bluerotation +=bluerotationVel;//get a rotation velocity
        sf::Transform blueRotate;//Create a transformation R
        blueRotate.rotate(bluerotation);
        
        sf::Transform blue= M * blueTransformation*blueRotate;//Create a transformation that is the center position transformation by the rotation transformation
        
        //Right ARM RECTANGLE
        sf::Transform rightarmTransformation;//create a transformation
        rightarmTransformation.translate(200,-25);//translate it to the center of the screen
        
        rightrotation +=rightrotationVel;//get a rotation velocity
        sf::Transform rightRotate;//Create a transformation R
        rightRotate.rotate(rightrotation);
        
        sf::Transform right= blue * rightarmTransformation*rightRotate;//Create a transformation that is the center position transformation by the rotation transformation
        
        //Left Arm Transformation
        sf::Transform leftarmTransformation;//create a transformation
        leftarmTransformation.translate(200,-25);//translate it to the center of the screen
        
        leftrotation +=leftrotationVel;//get a rotation velocity
        sf::Transform leftRotate;//Create a transformation R
        leftRotate.rotate(leftrotation);
        
        sf::Transform left= blue * leftarmTransformation*leftRotate;//Create a transformation that is the center position transformation by the rotation transformation
        
        
        //update GREEN lines
        for(int i=0;i<size;i++){
            lines[i].color=sf::Color::Green;
            lines[i].position=M.transformPoint(greenRect[i]);
            
        }
        
        
        //update BLUE lines
        for(int i=0;i<bluesize;i++){
            blueLines[i].color=sf::Color::Blue;
            blueLines[i].position=blue.transformPoint(blueRect[i]);
            
        }
        
        //update Right lines
        for(int i=0;i<armSize;i++){
            rightLines[i].color=sf::Color::Red;
            rightLines[i].position=right.transformPoint(RightArm[i]);
            
        }
        
        for(int i=0;i<armSize;i++){
            leftLines[i].color=sf::Color::Red;
            leftLines[i].position=left.transformPoint(leftArm[i]);
            
        }


        
        
        
        
        //prepare frame
        window.clear();
        
        
        window.draw(lines);
        
        window.draw(blueLines);
        
        window.draw(rightLines);
        
        window.draw(leftLines);
       
        
        
        
        // Finally, display rendered frame on screen
        window.display();
    } //loop back for next frame
    
    return EXIT_SUCCESS; 
}
