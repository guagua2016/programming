#include <iostream>
    
using namespace std;

#if defined(__GNUC__)
#define TVM_ATTRIBUTE_UNUSED __attribute__((unused))
#else
#define TVM_ATTRIBUTE_UNUSED
#endif


#define TVM_FUNC_REG_VAR_DEF                                            \
  ::tvm::runtime::Registry& __mk_ ## TVM


int main(int argc, char const *argv[])
{
      /* code */

  std::cout << TVM_FUNC_REG_VAR_DEF << std::endl;
  return 0;
}