//Chapter 1: Code examples (easier viewing)

//Sample C++ programs
//1. Hello World
    #include <iostream>

    void main() {
        cout << "Hello World" << endl;
    }

//2. Hello world definined
    #include <string.h>
    #invlude <stdio.h>

    class DISPLAY {
        public:
            DISPLAY (char *pc) {
                strncpy(str, pc, sizeof(str) -1 );
                str[sizeof(str) -1];
            }
            void output { puts(str) };

        private:
            char str[256];
    };

    void main() {
        DISPLAY text("Hello world");
        text.output();
    }
    //This implementation defines Display for us and uses is to
    //create a display object of hello world and output it.

