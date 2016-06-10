#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <IsrafilCore-api.h>


namespace Israfil {
namespace Base {
#define ISRAFILDBG

#ifdef ISRAFILDBG
# define dbg(x) std::cout \
  << "IsrafilDBG::"       \
  << __FUNCTION__         \
  << "() "                \
  << "@ "                 \
  << __TIMESTAMP__        \
  << "\n"                 \
  << __FILE__             \
  << " L"                 \
  << __LINE__             \
  << " \n"                \
  << # x " = "            \
  << (x)                  \
  << std::endl            \
  << std::endl

# define dbgerr(x) std::cout \
  << "IsrafilDBG::ERROR::"   \
  << __FUNCTION__            \
  << "() "                   \
  << "@ "                    \
  << __TIMESTAMP__           \
  << "\n"                    \
  << __FILE__                \
  << " L"                    \
  << __LINE__                \
  << " \n"                   \
  << # x " = "               \
  << (x)                     \
  << std::endl               \
  << std::endl
# define everWarn(x) std::cout             \
  << "\033[33mIsrafilDBG::Warning::\033[0m" \
  << __FUNCTION__                          \
  << "() "                                 \
  << "@ "                                  \
  << __TIMESTAMP__                         \
  << "\n"                                  \
  << __FILE__                              \
  << " L"                                  \
  << __LINE__                              \
  << " \n Warning MSG:"                    \
  << (x)                                   \
  << std::endl                             \
  << std::endl
# define everErr(x) std::cout            \
  << "\033[31mIsrafilDBG::ERROR::\033[0m" \
  << __FUNCTION__                        \
  << "() "                               \
  << "@ "                                \
  << __TIMESTAMP__                       \
  << "\n"                                \
  << __FILE__                            \
  << " L"                                \
  << __LINE__                            \
  << " \n Error MSG:"                    \
  << (x)                                 \
  << std::endl                           \
  << std::endl
# define everMsg(x) std::cout          \
  << "\033[32mIsrafilDBG::Msg::\033[0m" \
  << __FUNCTION__                      \
  << "() "                             \
  << "@ "                              \
  << __TIMESTAMP__                     \
  << "\n"                              \
  << __FILE__                          \
  << " L"                              \
  << __LINE__                          \
  << " \n Notice:"                     \
  << (x)                               \
  << std::endl                         \
  << std::endl
#endif // ifdef ISRAFILDBG
#ifdef ISRAFILDBGSILENT
# define dbg(x)
# define dbgerr(x)
#endif // ifdef ISRAFILDBGSILENT


// #define dbg(x) std::cout<< #x "= " << (x) <<std::endl;
// #define dbgerr(x) std::cout<< "ERROR: " #x "= " << (x) <<std::endl;
// #endif
// #endif


ISRAFILCORE_API int StringToInt(std::string Str);
}
}

#endif // UTILS_H
