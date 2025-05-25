#include "testlib.h"

int main() {
    registerValidation();  

    
    int m = inf.readInt(1, 1000, "m");
    inf.readSpace();  
    int n = inf.readInt(1, 1000, "n");
    inf.readEoln();   
     
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // THE VALUES SHOULD BE EITHER 1 OR 0
            inf.readInt(0, 1, "matrix element");
            // TO CHECK SPACE BETWEEN THE ELEMENTS
            if (j < n - 1) {
                inf.readSpace();
            }
        }
        inf.readEoln();  //END OF LINE AFTER EVERY ROW
    }

    inf.readEof();
    return 0;

}
