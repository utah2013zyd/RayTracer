INCLUDE_DIRECTORIES(../include)
SET(CMAKE_CXX_FLAGS "-pthread -std=c++11")
SET(EXECUTABLE_OUTPUT_PATH "../bin")
#SET(CMAKE_BUILD_TYPE Debug)
SET(SRC_LIST main.cpp
	lights.cpp
	Math.cpp
	photonmap.cpp
	Tracer.cpp
	object.cpp
	Renderer.cpp
	xmlload.cpp
	materials.cpp
	PhotonGenerator.cpp
	texture.cpp
	tinystr.cpp
	tinyxml.cpp
	tinyxmlerror.cpp
	tinyxmlparser.cpp
	)

ADD_EXECUTABLE(RayTracer ${SRC_LIST})
MESSAGE(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir "${PROJECT_SOURCE_DIR})
ADD_CUSTOM_COMMAND(TARGET RayTracer
		 OST_BUILD
		COMMAND cp ARGS -r ${PROJECT_SOURCE_DIR}/resources ${PROJECT_BINARY_DIR}/resources)
