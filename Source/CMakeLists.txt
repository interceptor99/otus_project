cmake_minimum_required(VERSION 3.19)

project(proj VERSION 1.0.0)

set(source_list Containers/vector.h
                Containers/list.h

                main.cpp )

add_executable(proj ${source_list})

foreach(FILE ${source_list})
get_filename_component(PARENT_DIR "${FILE}" PATH)

string(REPLACE "/" "\\" GROUP "${PARENT_DIR}")

set(GROUP "Source Files\\${GROUP}")


source_group("${GROUP}" FILES "${FILE}")

target_include_directories(proj PUBLIC ${PARENT_DIR})

endforeach()

set_target_properties(
	${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
