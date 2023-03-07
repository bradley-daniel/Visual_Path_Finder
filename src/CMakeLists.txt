#asm the hardest language, no cmake is!
macro(GET_SORUCES_LIST result curdir)
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
    SET(APPEND source_files "")
    FOREACH(child ${children})
        IF(IS_DIRECTORY ${curdir}/${child})
            aux_source_directory(${curdir}/${child} source_files)
            GET_SORUCES_LIST(sub_result ${curdir}/${child})
        ENDIF()
    ENDFOREACH()
    SET(${result} ${source_files})
endmacro()

GET_SORUCES_LIST(SOURCES_LIST ${CMAKE_CURRENT_SOURCE_DIR})

foreach(x ${SOURCES_LIST})
    message(STATUS ${x})
endforeach()

#message(STATUS ${SOURCES_LIST})

add_executable(${PROJECT_NAME} main.cpp ${source_files} ../main.cpp)