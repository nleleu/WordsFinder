project(wordfinder)


add_executable(combinator combinator.cpp dictionnary.cpp mainCombinator.cpp)

add_executable(boggleSolver coordinates.cpp boggleSolver.cpp dictionnary.cpp mainBoggleSolver.cpp)
