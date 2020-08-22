#include <Neo.h>
#include <MemoryUtility.h>
#include <Stack.h>
#include <Logger.h>

#include <PMM.h>

using namespace neo;

namespace neo{

 Stack<Page, 32*1024> MemoryStack;//32K Pages = 128 MByte

}
