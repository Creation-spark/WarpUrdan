#ifndef WarpUrdan_H
#define WarpUrdan_H

#include "wuCycle.h"
#include "wuSpace.h"

namespace wu {
    extern wuCycle* cycle;
    extern wuSpace* space;

    void WU_CreateModuls();
    void WU_DeleteModuls();
}

#endif // WarpUrdan_H

// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ ... }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]
// [============================->{ ... }<-============================]
// [=]<------------------------------------------------------------->[=]