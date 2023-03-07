macro(GETHEADERDIR result curdir)
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
    SET(header_dirs "")
    FOREACH(child ${children})
        IF(IS_DIRECTORY ${curdir}/${child})
            SET(header_dirs ${header_dirs} ${child})
        ENDIF()
    ENDFOREACH()
    SET(${result} ${header_dirs})
endmacro()

GETHEADERDIR(HEADERS ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE ${HEADERS})