execute_process(COMMAND "${Ice_SLICE2CPP_EXECUTABLE}"
                        "--output-dir=${CMAKE_CURRENT_BINARY_DIR}/clt"
                        "HelloWorld.ice"
      WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")
execute_process(COMMAND "${Ice_SLICE2CPP_EXECUTABLE}"
                        "--output-dir=${CMAKE_CURRENT_BINARY_DIR}/svr"
                        "HelloWorld.ice"
      WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")

aux_add_subdirectories()
