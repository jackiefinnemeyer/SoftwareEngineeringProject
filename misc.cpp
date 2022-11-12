
#include "misc.h"
#include <algorithm>
#include <string>


void printMe(string type) {
    if (type == "banner") {
        char banner[] = \
"   ######## ########   #######        ##    ###    ##    ##         ########   #######   #######  ##    ## \n \
     ##    ##     ## ##     ##       ##   ## ##   ###   ##         ##     ## ##     ## ##     ## ##   ## \n \
     ##    ##     ## ##     ##       ##  ##   ##  ####  ##         ##     ## ##     ## ##     ## ##  ## \n \
     ##    ########  ##     ##       ## ##     ## ## ## ## ####### ########  ##     ## ##     ## ##### \n \
     ##    ##   ##   ##     ## ##    ## ######### ##  ####         ##     ## ##     ## ##     ## ##  ## \n \
     ##    ##    ##  ##     ## ##    ## ##     ## ##   ###         ##     ## ##     ## ##     ## ##   ## \n \
     ##    ##     ##  #######   ######  ##     ## ##    ##         ########   #######   #######  ##    ##\n";
        cout << endl << banner << endl << endl;
    }
}

string codeName(string str1, string str2) {
    string id;

    for (int i = 0; i < str1.length(); i++) {
        if (isalpha(str1[i]))
            id += str1[i];
    }
    for (int i = 0; i < str2.length(); i++) {
        if (isalpha(str2[i]))
            id += str2[i];
    }

    transform(id.begin(), id.end(), id.begin(), ::tolower);

    return id;
}
