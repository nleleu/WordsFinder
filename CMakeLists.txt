project(wordfinder)


add_executable(combinator util.h combinator.cpp dictionnary.cpp mainCombinator.cpp)

add_executable(boggleSolver util.h coordinates.cpp boggleSolver.cpp dictionnary.cpp mainBoggleSolver.cpp)
