include_directories(${Boost_INCLUDE_DIRS})
include_directories(${SFML2_INCLUDE_DIRS})

set(LIBGAME0_SRC
  Animation.cc
  Entity.cc
  Random.cc
  Resource.cc
  World.cc
  TMPL_cCartesianEquation.cpp
  TMPL_cHalfLine.cpp
  TMPL_cLight.cpp
  TMPL_cLightLink.cpp
  TMPL_cLightList.cpp
  TMPL_cLightSource.cpp
  TMPL_cPoint.cpp
  TMPL_cPolygon.cpp
  TMPL_cPolygonList.cpp
  TMPL_cRaySegment.cpp
  TMPL_cSegment.cpp
  TMPL_cSeparateLight.cpp
  TMPL_cTriangle.cpp
  TMPL_cWall.cpp
)

add_library(game0 SHARED
  ${LIBGAME0_SRC}
)

target_link_libraries(game0
  ${Boost_LIBRARIES}
  ${SFML2_LIBRARIES}
)

set_target_properties(game0
  PROPERTIES
  VERSION ${CPACK_PACKAGE_VERSION}
  SOVERSION ${CPACK_PACKAGE_VERSION_MAJOR}
)

install(
  TARGETS game0
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
)
